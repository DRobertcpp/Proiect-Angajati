#include<iostream>758
#include<string.h>
#include <fstream>
#pragma warning(disable: 4996)
using namespace std;

class Angajat {
protected:
	char* nume;
	int salariu;
	char* parinte;
public:
	Angajat(const char*, const int, const char*);
	Angajat() { nume = 0; salariu = 0; parinte = 0; }
	Angajat(const Angajat&);
	virtual ~Angajat();
	Angajat& operator=(const Angajat&);
	virtual char* daFunctia() = 0;
	int getSalariu() { return salariu; }
	void setSalariu(int salariu) { this->salariu = salariu; }
	char* getParinte() { return parinte; }
	char* getNume() { return nume; }
	virtual void scrie(ostream& out) = 0;
};
//===========================================================================

class Muncitor :public Angajat {
public:
	Muncitor(const char*, const int, const char*);
	Muncitor() { nume = 0; salariu = 0; parinte = 0; }
	char* daFunctia();
	virtual void scrie(ostream& out);//scrie in fisier
	static Muncitor citeste();
	friend ostream& operator<<(ostream& out, const Muncitor M) {
		out << M.nume << " este un MUNCITOR cu salariul " << M.salariu << ", iar numele sefului sau este " << M.parinte << "." << endl;
		return out;
	}
};
//=========================================================================

class Manager : public Angajat {
public:
	Manager(const char*, const int, const char*);
	Manager() { nume = 0; salariu = 0; parinte = 0; }
	virtual void scrie(ostream& out) = 0;	
};
// ============================================================================

class TeamLeader : public Manager {
public:
	TeamLeader(const char*, const int, const char*);
	TeamLeader() { nume = 0; salariu = 0; parinte = 0; }
	char* daFunctia();
	virtual void scrie(ostream& out);
	static TeamLeader citeste();
	friend ostream& operator<<(ostream& out, const TeamLeader T) {
		out << T.nume << " este un Team Leader cu salariul " << T.salariu << ", iar numele sefului sau este " << T.parinte << endl;
		return out;
	}
};
// ============================================================================

class SefDepartament : public Manager {
protected:
	char* departament;
public:
	SefDepartament(const char*, const int,  const char*, const char*);
	SefDepartament() { nume = 0; salariu = 0; parinte = 0; departament = 0; }
	SefDepartament(const SefDepartament&);
	virtual ~SefDepartament();
	SefDepartament& operator=(const SefDepartament&);
	char* daFunctia();
	char* daDepartament() { return departament; }
	virtual void scrie(ostream& out);
	static SefDepartament citeste();
	friend ostream& operator<<(ostream& out, const SefDepartament S) {
		out << S.nume << " este un Sef de Departament cu salariul " << S.salariu << ", iar numele sefului sau este " << S.parinte <<  endl;
		return out;
	}
};
// ============================================================================

class CEO : public Manager {
public:
	CEO(const char*, const int, const char*);
	CEO() { nume = 0; salariu = 0; parinte = 0; }
	char* daFunctia();
	char* daDepartament() {	return 0; }
	virtual void scrie(ostream& out);
	static CEO citeste();
	friend ostream& operator<<(ostream& out, const CEO C) {
		out << C.nume << " este un CEO cu salariul " << C.salariu << endl;
		return out;
	}
};
//============================================================================

template<class Element>
class Meniu {
protected:
	Element* tab;
	int index;
public:
	Meniu();
	~Meniu();
	Meniu<Element>& operator+=(const Element Angajat);
	int TotalCheltuieli();
	void afiseazaAngajati();
	void scrieAngajatiInFisier(string);
	void adaugaAngajat(const Element);
	void SchimbaSalariu(char*, int);
};
//============================================================================

class Aux {
	Meniu<CEO> C;
	Meniu<SefDepartament> SD;
	Meniu<TeamLeader> TL;
	Meniu<Muncitor> M;
public:
	Meniu<CEO> getC(){ return C; }
	Meniu<SefDepartament> getSD() { return SD; }
	Meniu<TeamLeader> getTL() { return TL; }
	Meniu<Muncitor> getM() { return M; }
	void start();
	void adaugaAngajat();
	void afiseaza();
	void Schimba(char*, int);
	void citesteAngajatiDinFisier(string);
};
