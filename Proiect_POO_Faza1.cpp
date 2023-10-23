#include<iostream>
using namespace std;

class MarcuLeonardo_Pacient {
public:
	string nume;
	int varsta;
	static int numar_total_pacienti;
	const string camera_consultatie;
	int* id;

	MarcuLeonardo_Pacient() : camera_consultatie("Camera 100")
	{
		this->nume = "Andrei";
		this->varsta = 18;
		id = new int(0);
		numar_total_pacienti++;
	}

	MarcuLeonardo_Pacient(string numepacient, const string camera) : camera_consultatie(camera)
	{
		this->nume = numepacient;
		this->varsta = 19;
		id = new int(1);
		numar_total_pacienti++;
	}

	MarcuLeonardo_Pacient(string numepacient, int varstapacient, int idul, const string camera) : camera_consultatie(camera)
	{
		this->nume = numepacient;
		this->varsta = varstapacient;
		id = new int(idul);
		numar_total_pacienti++;

	}

	~MarcuLeonardo_Pacient() {
		delete id;
	}

	static int Numarul_Total_Al_Pacientilor() {
		return numar_total_pacienti;
	}

	void afisare_pacient() {
		cout << "Nume: " << MarcuLeonardo_Pacient::nume << "; Varsta: " << MarcuLeonardo_Pacient::varsta << "; Camera: " << MarcuLeonardo_Pacient::camera_consultatie << "; ID: " << *id << endl;
	}
};

int MarcuLeonardo_Pacient::numar_total_pacienti = 0;

class MarcuLeonardo_Medicament {
public:
	string nume;
	float pret;
	int cantitate;
	const string categorie;
	static int numar_total_medicamente;
	int* cod;

	MarcuLeonardo_Medicament() : categorie("Administrare Orala")
	{
		this->nume = "Paracetamol";
		this->pret = 0.75;
		this->cantitate = 2;
		cod = new int(100);
		numar_total_medicamente++;
	}

	MarcuLeonardo_Medicament(string numemedicament, const string cat) : categorie(cat)
	{
		this->nume = numemedicament;
		this->pret = 2.75;
		this->cantitate = 3;
		cod = new int(101);
		numar_total_medicamente++;
	}

	MarcuLeonardo_Medicament(string nume, float pret, int q, int codul, const string cat) : categorie(cat)
	{
		this->nume = nume;
		this->pret = pret;
		this->cantitate = q;
		cod = new int(codul);
		numar_total_medicamente++;
	}

	~MarcuLeonardo_Medicament() {
		delete cod;
	}

	static int nrmed() {
		return numar_total_medicamente;
	}

	static float calcul(float pret, int cantitate) {
		return pret * cantitate;
	}

	void afisare_medicament() {
		cout << "Numele medicamentului: " << MarcuLeonardo_Medicament::nume << "; Cantitatea lui: " << MarcuLeonardo_Medicament::cantitate << "; Pretul pe pastila: " << MarcuLeonardo_Medicament::pret << "; Categoria din care face parte: " << MarcuLeonardo_Medicament::categorie << "; Codul aferent: " << *cod << "; Pretul final: " << MarcuLeonardo_Medicament::calcul(pret, cantitate) << endl;
	}
};

int MarcuLeonardo_Medicament::numar_total_medicamente = 0;

class MarcuLeonardo_PersonalMedical {
public:
	string nume;
	float salariu;
	const string spital;
	static int numar_total_personal;
	char* specializare;

	MarcuLeonardo_PersonalMedical(const char* special) : spital("Floreasca")
	{
		this->nume = "Andreea Glavan";
		this->salariu = 6500;
		specializare = new char[strlen(special) + 1];
		strcpy(specializare, special);
		numar_total_personal++;
	}

	MarcuLeonardo_PersonalMedical(const char* special, string nume) : spital("Floreasca")
	{
		this->nume = nume;
		this->salariu = 10000;
		specializare = new char[strlen(special) + 1];
		strcpy(specializare, special);
		numar_total_personal++;
	}

	MarcuLeonardo_PersonalMedical(string nume, float salariu, const char* special, const string sp) : spital(sp)
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

	~MarcuLeonardo_PersonalMedical() {
		delete[] specializare;
	}

	void afisare_personal() {
		cout << "Nume: " << MarcuLeonardo_PersonalMedical::nume << "; Salariul pe care il are: " << MarcuLeonardo_PersonalMedical::salariu << "; Specializarea: " << specializare << "; Spitalul de care apartine: " << MarcuLeonardo_PersonalMedical::spital << endl;
	}
};

int MarcuLeonardo_PersonalMedical::numar_total_personal = 0;

int main() {

	// CLASA 1
	cout << "-------- PACIENT --------" << endl;
	cout << "" << endl;

	MarcuLeonardo_Pacient pacient0;
	pacient0.afisare_pacient();
	MarcuLeonardo_Pacient pacient1("Gabriel", "Camera 101");
	pacient1.afisare_pacient();
	MarcuLeonardo_Pacient pacient2("Andreea", 20, 2, "Camera 102");
	pacient2.afisare_pacient();
	int x = MarcuLeonardo_Pacient::Numarul_Total_Al_Pacientilor();
	cout << "Numarul total de pacienti este: " << x << endl;
	cout << "" << endl;

	delete pacient0.id;
	delete pacient1.id;
	delete pacient2.id;

	// CLASA 2
	cout << "------- MEDICAMENTE -------" << endl;
	cout << "" << endl;

	MarcuLeonardo_Medicament medicament1;
	medicament1.afisare_medicament();
	MarcuLeonardo_Medicament medicament2("Bioflu", "Administrare nazala");
	medicament2.afisare_medicament();
	MarcuLeonardo_Medicament medicament3("Tension", 1, 5, 102, "Administrare sublinguala");
	medicament3.afisare_medicament();
	int y = MarcuLeonardo_Medicament::nrmed();
	cout << "Numarul total de medicamente este: " << y << endl;

	delete medicament1.cod;
	delete medicament2.cod;
	delete medicament3.cod;

	// CLASA 3
	cout << "" << endl;
	cout << "---------- PERSONALUL MEDICAL ----------" << endl;
	cout << "" << endl;

	MarcuLeonardo_PersonalMedical personal1("Chirurgie");
	personal1.afisare_personal();
	MarcuLeonardo_PersonalMedical personal2("Neurologie", "Andrei Nistor");
	personal2.afisare_personal();
	MarcuLeonardo_PersonalMedical personal3("Dinu Maria", 12000, "Patologie", "Bucuresti");
	personal3.afisare_personal();
	int z = MarcuLeonardo_PersonalMedical::nr_pers();
	cout << "Numarul total de personal este: " << z << endl;

	delete[] personal1.specializare;
	delete[] personal2.specializare;
	delete[] personal3.specializare;

}
