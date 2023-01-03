#include "Header.h"
#include<fstream>

Angajat::Angajat(const char* nume, const int salariu, const char* parinte ) {
	this->nume = new char[strlen(nume) + 1];
	strcpy(this->nume, nume);
	this->salariu = salariu;
	this->parinte = new char[strlen(parinte) + 1];
	strcpy(this->parinte, parinte);
}

Angajat::Angajat(const Angajat& a) {
	nume = new char[strlen(a.nume) + 1];
	strcpy(nume, a.nume);
	salariu = a.salariu;
	parinte = new char[strlen(a.parinte) + 1];
	strcpy(parinte, a.parinte);
}

Angajat::~Angajat() {
	if (nume)delete[] nume;
	if (parinte)delete[] parinte;
}

Angajat& Angajat::operator=(const Angajat& a) {
	if (this != &a) {
		if (nume)delete[] nume;
		nume = new char[strlen(a.nume) + 1];
		strcpy(nume, a.nume);
		salariu = a.salariu;
		if (parinte)delete[] parinte;
		parinte = new char[strlen(a.parinte) + 1];
		strcpy(parinte, a.parinte);
	}
	return *this;
}
//===============================================================
Muncitor::Muncitor(const char* nume, const int salariu,  const char* parinte) : Angajat(nume, salariu, parinte) {}

char* Muncitor::daFunctia() {
	char functia[100] = "Muncitor";
	return functia;
}

void Muncitor::scrie(ostream& out) {
	out << "Muncitor ";
	out << nume << " ";
	out << salariu << " ";
	out << parinte << " ";
	out << endl;
}

Muncitor Muncitor::citeste() {
	char* nume = new char[20];
	char* parinte = new char[20];
	int salariu;
	cout << "\nAdaugare Muncitor:";
	cout << "\n\tNume:";
	cin >> nume;
	cout << "\n\tSalariu:";
	cin >> salariu;
	cout << "\n\tNume Parinte:";
	cin >> parinte;
	return Muncitor(nume, salariu, parinte);
}
//===============================================================

Manager::Manager(const char* nume, const int salariu, const char* parinte) :Angajat(nume, salariu, parinte) {}
//===============================================================

TeamLeader::TeamLeader(const char* nume, const int salariu,  const char* parinte) : Manager(nume, salariu, parinte) {}

char* TeamLeader::daFunctia() {
	char functia[100] = "TeamLeader";
	return functia;
}

void TeamLeader::scrie(ostream& out) {
	out << "TeamLeader ";
	out << nume << " ";
	out << salariu << " ";
	out << parinte << " ";
	out << endl;	
}

TeamLeader TeamLeader::citeste() {
	char* nume = new char[20];
	char* parinte = new char[20];
	int salariu;
	cout << "\nAdaugare Team Leader:";
	cout << "\n\tNume:";
	cin >> nume;
	cout << "\n\tSalariu:";
	cin >> salariu;
	cout << "\n\tNume Parinte:";
	cin >> parinte;
	return TeamLeader(nume, salariu, parinte);
}
//===============================================================

SefDepartament::SefDepartament(const char* nume, const int salariu, const char* parinte, const char* departament) :Manager(nume, salariu, parinte) {
	this->departament = new char[strlen(departament) + 1];
	strcpy(this->departament, departament);
}

SefDepartament::SefDepartament(const SefDepartament& a) : Manager(a.nume, a.salariu, a.parinte) {
	departament = new char[strlen(a.departament) + 1];
	strcpy(departament, a.departament);
}

SefDepartament::~SefDepartament() {
	if (departament)delete[] departament;
}

SefDepartament& SefDepartament::operator=(const SefDepartament& a) {
	if (this != &a) {
		if (nume)delete[] nume;
		nume = new char[strlen(a.nume) + 1];
		strcpy(nume, a.nume);
		salariu = a.salariu;
		if (parinte)delete[] parinte;
		parinte = new char[strlen(a.parinte) + 1];
		strcpy(parinte, a.parinte);
		if (departament)delete[] departament;
		departament = new char[strlen(a.departament) + 1];
		strcpy(departament, a.departament);
	}
	return *this;
}

char* SefDepartament::daFunctia() {
	char functia[100] = "SefDepartament";
	return functia;
}

void SefDepartament::scrie(ostream& out) {
	out << "SefDepartament ";
	out << nume << " ";
	out << salariu << " ";
	out <<	parinte << " ";
	out << departament << " ";
	out << endl;
}

SefDepartament SefDepartament::citeste() {
	char* nume = new char[20];
	char* parinte = new char[20];
	char* departament = new char[20];
	int salariu;
	cout << "\nAdaugare Sef Departament:";
	cout << "\n\tNume:";
	cin >> nume;
	cout << "\n\tSalariu:";
	cin >> salariu;
	cout << "\n\tNume Parinte:";
	cin >> parinte;
	cout << "\n\tDepartamentul:";
	cin >> departament;
	return SefDepartament(nume, salariu,parinte, departament);
}
//===============================================================

CEO::CEO(const char* nume, const int salariu, const char* parinte) :Manager(nume, salariu, parinte) {}

char* CEO::daFunctia() {
	char functia[100] = "CEO";
	return functia;
}

void CEO::scrie(ostream& out) {
	out << "CEO ";
	out << nume << " ";
	out << salariu << " ";
	out << parinte << " ";
	out << endl;
}

CEO CEO::citeste() {
	char* nume = new char[20];
	int salariu;
	cout << "\nAdaugare CEO:";
	cout << "\n\tNume:";
	cin >> nume;
	cout << "\n\tSalariu:";
	cin >> salariu;
	return CEO(nume, salariu, "0");
}
//===============================================================

template <class Element>
Meniu<Element>::Meniu() {
	index = -1;
	tab = new Element[100];
}

template <class Element>
Meniu<Element>::~Meniu() {}

template <class Element>
void Meniu<Element>::adaugaAngajat(const Element e) {
	tab[++index] = e;
}

template<typename Element>
Meniu<Element>& Meniu<Element>::operator+=(const Element e) {
	tab[++index] = e;
}

template <class Element>
int Meniu<Element>::TotalCheltuieli() {
	int	total = 0;
	for (int i = 0; i <= index; i++) {
		total = total + tab[i].getSalariu();
	}
	return total;
}

template <class Element>
void Meniu<Element>::afiseazaAngajati() {
	if (index == -1) {
		cout << "\nNu exista Angajati.";
		return;
	}
	for (int i = 0; i <= index; i++) {
		cout << tab[i] << endl;
	}
}

template <class Element>
void Meniu<Element>::scrieAngajatiInFisier(string numeFisier) {
	ofstream out(numeFisier);
	if (out.good()) {
		for (int i = 0; i <= index; i++) {
			tab[i].scrie(out);
		}
		out.close();
	}
	else
		cout << endl << "Eroare la salvare!" << endl;
}

template <class Element>
void Meniu<Element>::SchimbaSalariu(char* nume, int salariu) {
	for (int i = 0; i <= index; i++) {
		char* d = tab[i].getNume();
		if (strcmp(d, nume) == 0) {
			tab[i].setSalariu(salariu);
		}
	}
}
//=================================================================================================

void Aux::start() {
	citesteAngajatiDinFisier("Muncitor.txt");
	citesteAngajatiDinFisier("TeamLeader.txt");
	citesteAngajatiDinFisier("SefDepartament.txt");
	citesteAngajatiDinFisier("CEO.txt");
	int raspuns;
	do {
		cout << "\nAlegeti operatia dorita:";
		cout << "\n\t1) Adaugare angajat.";
		cout << "\n\t2) Afisare lista angajati.";
		cout << "\n\t3) Calcul total cheltuieli.";
		cout << "\n\t4) Modificare salariu angajat.";
		cout << "\n\t5) Iesire!";
		cout << "\n\n-->";
		cin >> raspuns;
		if (raspuns == 1)
			adaugaAngajat();
		else if (raspuns == 2) {
			afiseaza();
		}
		else if (raspuns == 3) {
			double S = 0;
			S += M.TotalCheltuieli();
			S += TL.TotalCheltuieli();
			S += SD.TotalCheltuieli();
			S += C.TotalCheltuieli();
			cout << S;
		}
		else if (raspuns == 4) {
			char* nume = new char[20];
			cout << "\nIntroduce-ti numele angajatului:";
			cin >> nume;
			int salariu;
			cout << "\nIntroduce-ti noul salariu:";
			cin >> salariu;
			Schimba(nume, salariu);
		}
	} while (raspuns != 5);
	TL.scrieAngajatiInFisier("TeamLeader.txt");
	SD.scrieAngajatiInFisier("SefDepartament.txt");
	C.scrieAngajatiInFisier("CEO.txt");
	M.scrieAngajatiInFisier("Muncitor.txt");
}

void Aux::adaugaAngajat() {
	int raspuns;
	cout << "\nAlegeti tipul angajatului pe care doriti sa-l adaugati:";
	cout << "\n\t1) Muncitor";
	cout << "\n\t2) Manager";
	cout << "\n\n-->";
	cin >> raspuns;

	if (raspuns == 1)
		M.adaugaAngajat(Muncitor::citeste());
	else if (raspuns == 2) {
		int raspuns2;
		cout << "\nAlegeti tipul managerului pe care doriti sa-l adaugati:";
		cout << "\n\t1) TeamLeader";
		cout << "\n\t2) SefDepartament";
		cout << "\n\t3) CEO";
		cout << "\n\n-->";
		cin >> raspuns2;
		if (raspuns2 == 1)
			TL.adaugaAngajat(TeamLeader::citeste());
		else if (raspuns2 == 2)
			SD.adaugaAngajat(SefDepartament::citeste());
		else if (raspuns2 == 3)
			C.adaugaAngajat(CEO::citeste()); // this devine NULL
	}
}

void Aux::afiseaza() {
	cout << "\t\tCEO: \n";
	C.afiseazaAngajati();
	cout << "==================================\n\n";
	cout << "\t\tSefi de Departament: \n";
	SD.afiseazaAngajati();
	cout << "==================================\n\n";
	cout << "\t\tTeam Leaderi: \n";
	TL.afiseazaAngajati();
	cout << "==================================\n\n";
	cout << "\t\tMuncitori: \n";
	M.afiseazaAngajati();
	cout << "==================================\n\n";
}

void Aux::Schimba(char* id, int salariu) {
	M.SchimbaSalariu(id, salariu);
	TL.SchimbaSalariu(id, salariu);
	SD.SchimbaSalariu(id, salariu);
	C.SchimbaSalariu(id, salariu);
}

void Aux::citesteAngajatiDinFisier(string numeFisier) {
	ifstream in(numeFisier);
	if (in.good()) {
		char* functia = new char[20];
		while (in >> functia) {
			char* nume = new char[20];
			char* parinte = new char[10];
			char* departament = new char[20];
			int salariu;
			if (strcmp(functia, "Muncitor")==0) {
				in >> nume;
				in >> salariu;
				in >> parinte;
				M.adaugaAngajat(Muncitor(nume, salariu, parinte));
			}
			if (strcmp(functia, "TeamLeader")==0) {
				in >> nume;
				in >> salariu;
				in >> parinte;
				TL.adaugaAngajat(TeamLeader(nume, salariu, parinte));
			}
			if (strcmp(functia ,"SefDepartament")==0) {
				in >> nume;
				in >> salariu;
				in >> parinte;
				in >> departament;
				SD.adaugaAngajat(SefDepartament(nume, salariu, parinte, departament));
			}
			if (strcmp(functia, "CEO")==0) {
				in >> nume;
				in >> salariu;
				in >> parinte;
				C.adaugaAngajat(CEO(nume, salariu, parinte));
			}
		}
		in.close();
	}
	else
		cout << endl << "Eroare la salvare!" << endl;
}
//===============================================================

int main() {
	Aux program;
	program.start();
	return 0;
}