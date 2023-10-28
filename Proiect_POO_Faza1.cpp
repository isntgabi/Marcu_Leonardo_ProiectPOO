#include<iostream>
using namespace std;

class Pacient {
private:
	string nume;
	int varsta;
	static int numar_total_pacienti;
	const string camera_consultatie;
	int* id;
public: 
	Pacient() : camera_consultatie("Camera 100")
	{
		this->nume = "Andrei";
		this->varsta = 18;
		id = new int(0);
		numar_total_pacienti++;
	}

	Pacient(string numepacient, const string camera) : camera_consultatie(camera)
	{
		this->nume = numepacient;
		this->varsta = 19;
		id = new int(1);
		numar_total_pacienti++;
	}

	Pacient(string numepacient, int varstapacient, int idul, const string camera) : camera_consultatie(camera)
	{
		this->nume = numepacient;
		this->varsta = varstapacient;
		id = new int(idul);
		numar_total_pacienti++;

	}

	~Pacient() {
		delete id;
	}
	Pacient(const Pacient& p) : camera_consultatie(p.camera_consultatie) {
		nume = p.nume;
		varsta = p.varsta;
		id = new int(*p.id);
		numar_total_pacienti++;
	}

	string getNume() const {
		return nume;
	}

	int getID() const {
		return *id;
	}

	void setNume(const string& NumeNou) {
		nume = NumeNou;
	}

	int GetVarsta() const {
		return varsta;
	}

	void SetVarsta(int VarstaNoua) {
		varsta = VarstaNoua;
	}

	string GetCamera() const {
		return camera_consultatie;
	}
	
	int GetID() const {
		return *id;
	}

	static int Numarul_Total_Al_Pacientilor() {
		return numar_total_pacienti;
	}

	void afisare_pacient() {
		cout << "Nume: " << Pacient::nume << "; Varsta: " << Pacient::varsta << "; Camera: " << Pacient::camera_consultatie << "; ID: " << *id << endl;
	}

	friend void Functie1(const Pacient& pacient);
	friend void Functie2(const Pacient& pacient);
};

int Pacient::numar_total_pacienti = 0;

void Functie1(const Pacient& pacient) {
	cout << "Nume pacient: " << pacient.getNume() << endl;
}

void Functie2(const Pacient& pacient) {
	cout << "Varsta pacient: " << pacient.GetVarsta() << endl;
}
class Medicament {
private:
	string nume;
	float pret;
	int cantitate;
	const string categorie;
	static int numar_total_medicamente;
	int* cod;
public:

	Medicament() : categorie("Administrare Orala")
	{
		this->nume = "Paracetamol";
		this->pret = 0.75;
		this->cantitate = 2;
		cod = new int(100);
		numar_total_medicamente++;
	}

	Medicament(string numemedicament, const string cat) : categorie(cat)
	{
		this->nume = numemedicament;
		this->pret = 2.75;
		this->cantitate = 3;
		cod = new int(101);
		numar_total_medicamente++;
	}

	Medicament(string nume, float pret, int q, int codul, const string cat) : categorie(cat)
	{
		this->nume = nume;
		this->pret = pret;
		this->cantitate = q;
		cod = new int(codul);
		numar_total_medicamente++;
	}

	~Medicament() {
		delete cod;
	}

	string getNume() const {
		return nume;
	}

	float getPret() const {
		return pret;
	}

	int getCod() const {
		return *cod;
	}
	int getCantitate() const {
		return cantitate;
	}

	string getCategorie() const {
		return categorie;
	}
	void setNume(const string& NumeNou) {
		nume = NumeNou;
	}
	void setCantitate(int cantitateNoua) {
		cantitate = cantitateNoua;
	}


	static int nrmed() {
		return numar_total_medicamente;
	}

	static float calcul(float pret, int cantitate) {
		return pret * cantitate;
	}

	void afisare_medicament() {
		cout << "Numele medicamentului: " << Medicament::nume << "; Cantitatea lui: " << Medicament::cantitate << "; Pretul pe pastila: " << Medicament::pret << "; Categoria din care face parte: " << Medicament::categorie << "; Codul aferent: " << *cod << "; Pretul final: " << Medicament::calcul(pret, cantitate) << endl;
	}

	friend void Functie3(const Medicament& medicament);
	friend void Functie4(const Medicament& medicament);
};

int Medicament::numar_total_medicamente = 0;

void Functie3(const Medicament& medicament) {
	float valoare = medicament.pret * medicament.cantitate;
	cout << "Medicamentul " << medicament.nume << " are valoarea stocului de: " << valoare << endl;
}

void Functie4(const Medicament& medicament) {
	cout << "Medicamentul " << medicament.nume << " face parte din categoria: " << medicament.categorie << endl;
}

class PersonalMedical {
private:
	string nume;
	float salariu;
	const string spital;
	static int numar_total_personal;
	char* specializare;
public:

	PersonalMedical(const char* special) : spital("Floreasca")
	{
		this->nume = "Andreea Glavan";
		this->salariu = 6500;
		specializare = new char[strlen(special) + 1];
		strcpy(specializare, special);
		numar_total_personal++;
	}

	PersonalMedical(const char* special, string nume) : spital("Floreasca")
	{
		this->nume = nume;
		this->salariu = 10000;
		specializare = new char[strlen(special) + 1];
		strcpy(specializare, special);
		numar_total_personal++;
	}

	PersonalMedical(string nume, float salariu, const char* special, const string sp) : spital(sp)
	{
		this->nume = nume;
		this->salariu = salariu;
		specializare = new char[strlen(special) + 1];
		strcpy(specializare, special);
		numar_total_personal++;
	}

	static int nr_pers() {
		return numar_total_personal;
	}

	~PersonalMedical() {
		delete[] specializare;
	}

	string getNume() const {
		return nume;
	}

	float getSalariu() const {
		return salariu;
	}

	string getSpital() const {
		return spital;
	}

	char getSpecializare() const {
		return *specializare;
	}

	void setNume(const string& nume) {
		this->nume = nume;
	}

	void setSalariu(const float& salariu) {
		this->salariu = salariu;
	}

	void afisare_personal() {
		cout << "Nume: " << PersonalMedical::nume << "; Salariul pe care il are: " << PersonalMedical::salariu << "; Specializarea: " << specializare << "; Spitalul de care apartine: " << PersonalMedical::spital << endl;
	}

	friend void Functie5(const PersonalMedical& personal);
	friend void Functie6(const PersonalMedical& personal);
};

int PersonalMedical::numar_total_personal = 0;

void Functie5(const PersonalMedical& personal)
{
	cout << "Numele personalului medical este: " << personal.getNume() << endl;
}

void Functie6(const PersonalMedical& personal)
{
	cout << "Salariul persoanei " << personal.getNume() << " este de: " << personal.getSalariu();
}

int main() {

	// CLASA 1
	cout << "-------- PACIENT --------" << endl;
	cout << "" << endl;

	Pacient pacient0;
	pacient0.afisare_pacient();
	Pacient pacient1("Gabriel", "Camera 101");
	pacient1.afisare_pacient();
	Pacient pacient2("Andreea", 20, 2, "Camera 102");
	pacient2.afisare_pacient();
	int x = Pacient::Numarul_Total_Al_Pacientilor();
	cout << "Numarul total de pacienti este: " << x << endl;
	cout << "" << endl;

	Pacient pacient3 = pacient2; // constructorul de copiere
	cout << "Nume pacient 3: " << pacient3.getNume() << endl;
	cout << "Varsta pacient 3: " << pacient3.GetVarsta() << endl;

	pacient1.setNume("Cristina");
	pacient1.SetVarsta(25);

	cout << "Nume pacient 1: " << pacient1.getNume() << endl;
	cout << "Varsta pacient 1: " << pacient1.GetVarsta() << endl;

	Functie1(pacient2);
	Functie2(pacient3);

	// CLASA 2
	cout << "" << endl;
	cout << "------- MEDICAMENTE -------" << endl;
	cout << "" << endl;

	Medicament medicament1;
	medicament1.afisare_medicament();
	Medicament medicament2("Bioflu", "Administrare nazala");
	medicament2.afisare_medicament();
	Medicament medicament3("Tension", 1, 5, 102, "Administrare sublinguala");
	medicament3.afisare_medicament();
	int y = Medicament::nrmed();
	cout << "Numarul total de medicamente este: " << y << endl;

	Medicament medicament4 = medicament3; // constructorul de copiere
	cout << "Nume medicament 3: " << medicament3.getNume() << endl;
	cout << "Categorie medicament 3: " << medicament3.getCategorie() << endl;
	medicament4.afisare_medicament();

	medicament3.setNume("Tertensif");
	medicament3.setCantitate(10);

	Functie3(medicament2);
	Functie4(medicament3);


	// CLASA 3
	cout << "" << endl;
	cout << "---------- PERSONALUL MEDICAL ----------" << endl;
	cout << "" << endl;

	PersonalMedical personal1("Chirurgie");
	personal1.afisare_personal();
	PersonalMedical personal2("Neurologie", "Andrei Nistor");
	personal2.afisare_personal();
	PersonalMedical personal3("Dinu Maria", 12000, "Patologie", "Bucuresti");
	personal3.afisare_personal();
	int z = PersonalMedical::nr_pers();
	cout << "Numarul total de personal este: " << z << endl;

	PersonalMedical personal4 = personal3; // constructorul de copiere
	cout << "Nume personal medical 3: " << personal3.getNume() << endl;
	cout << "Salariul personalului medical 3: " << personal3.getSalariu() << endl;

	personal3.setNume("Maria Bica");
	personal3.setSalariu(11345);

	Functie5(personal3);
	Functie6(personal4);

}
