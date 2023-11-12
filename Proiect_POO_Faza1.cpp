#include<iostream>
#include<string>
using namespace std;


class Pacient {
private:
	string nume;
	int varsta;
	string gen;
	const string camera_consultatie;
	int* id;
	bool analize;
	static int numar_total_pacienti;
	float greutate;
	float inaltime;

public:

	Pacient() : camera_consultatie("Camera 100")
	{
		this->nume = "Andrei Apostol";
		this->varsta = 20;
		this->gen = "Masculin";
		this->analize = 1;
		id = new int(0);
		this->inaltime = 180;
		this->greutate = 80;
		numar_total_pacienti++;
	}

	Pacient(int varsta) : camera_consultatie("Camera 101")
	{
		this->nume = "Carla Popescu";
		this->varsta = varsta;
		this->gen = "Feminin";
		this->analize = 0;
		id = new int(1);
		this->inaltime = 172;
		this->greutate = 65;
		numar_total_pacienti++;
	}

	Pacient(string nume, int varsta, string gen) : camera_consultatie("Camera 102")
	{
		this->nume = nume;
		this->varsta = varsta;
		this->gen = gen;
		this->analize = 1;
		id = new int(2);
		this->inaltime = 170;
		this->greutate = 61;
		numar_total_pacienti++;
	}

	Pacient(string nume, int varsta, string gen, int analize, int id, const string camera, float inaltime, float greutate) : camera_consultatie(camera)
	{
		this->nume = nume;
		this->varsta = varsta;
		this->gen = gen;
		this->analize = analize;
		this->id = new int(id);
		this->inaltime = inaltime;
		this->greutate = greutate;
		numar_total_pacienti++;
	}

	//constructorul de copiere
	Pacient(const Pacient& pacient) : camera_consultatie(pacient.camera_consultatie)
	{
		this->nume = pacient.nume;
		this->varsta = pacient.varsta;
		this->gen = pacient.gen;
		this->analize = pacient.analize;
		this->inaltime = pacient.inaltime;
		this->greutate = pacient.greutate;
		if (pacient.id != nullptr) 
		{
			this->id = new int(*pacient.id);
		}
		else 
		{
			this->id = nullptr;
		}
		numar_total_pacienti++;
	}

	string getNume() {
		return this->nume;
	}

	int getVarsta() {
		return this->varsta;
	}

	string getGen() {
		return this->gen;
	}

	bool getAnalize() {
		return this->analize;
	}

	int getID() {
		if (id != nullptr)
		{
			return *this->id;
		}
	}

	float getInaltime() {
		return this->inaltime;
	}

	float getGreutate() {
		return this->greutate;
	}

	void setInaltime(float inaltime) {
		this->inaltime = inaltime;
	}

	void setGreutate(float greutate) {
		this->greutate = greutate;
	}

	void setNume(string nume)
	{
		if (nume.length() > 3)
		{
			this->nume = nume;
		}
	}
	
	void setVarsta(int varsta)
	{
		this->varsta = varsta;
	}

	void setGen(string gen)
	{
		this->gen = gen;
	}

	void setAnalize(bool analize)
	{
		this->analize = analize;
	}

	void setID(int *id)
	{
		if (id != nullptr)
		{
			this->id = id;
		}
	}

	Pacient& operator=(const Pacient& pacient)
	{
		if (this != &pacient)
		{
			delete this->id;

			this->nume = pacient.nume;
			this->varsta = pacient.varsta;
			this->gen = pacient.gen;
			this->analize = pacient.analize;
			this->inaltime = pacient.inaltime;
			this->greutate = pacient.greutate;
			
			if (pacient.id != nullptr) 
			{
				this->id = new int(*pacient.id);
			}
			else 
			{
				this->id = nullptr;
			}
		}
		return *this;
	}

	//dezalocare
	~Pacient()
	{
		if (this->id != NULL)
		{
			delete[] this->id;
			this->id = NULL;
		}
	}

	static int Numarul_Total_Al_Pacientilor() {
		return numar_total_pacienti;
	}

	void afisare_pacient() {
		cout << "ID Pacient: " << *id << endl;
		cout << "Nume Pacient: " << nume << "; Varsta pacient: " << varsta <<"; Inaltime: "<<inaltime<<"; Greutate: "<<greutate<<"; Genul pacientului: " << gen << "; Camera de consultatie: " << camera_consultatie << "; Are analizele facute?: ";
		if (this->analize == true)
		{
			cout << "DA" << endl;
		}
		else
		{
			cout << "NU" << endl;
		}

	}

	static int afisare_numar_total_pacienti() {
		return numar_total_pacienti;
	}

	friend void calcul_imc(const Pacient& pacient);
	friend void afisare_detalii_pacient(const Pacient& pacient);

	friend ostream& operator<<(ostream& consola, const Pacient& pacient)
	{
		if (pacient.id != nullptr)
		{
			consola << "ID: " << *pacient.id << endl;
		}

		cout << "Nume Pacient: " << pacient.nume << "; Varsta pacient: " << pacient.varsta << "; Inaltime: " << pacient.inaltime << "; Greutate: " << pacient.greutate << "; Genul pacientului: " << pacient.gen << "; Camera de consultatie: " << pacient.camera_consultatie << "; Are analizele facute?: ";
		if (pacient.analize == true)
		{
			cout << "DA" << endl;
		}
		else
		{
			cout << "NU" << endl;
		}
		return consola;
	}

	friend istream& operator>>(istream& tastatura, Pacient& pacient) {
		cout << "Introduceti numele pacientului: "; getline(tastatura, pacient.nume);
		cout << "Introduceti varsta pacientului: "; tastatura >> pacient.varsta;
		cout << "Introduceti genul pacientului: "; tastatura >> pacient.gen;
		cout << "Introduceti inaltimea pacientului: "; tastatura >> pacient.inaltime;
		cout << "Introduceti greutatea pacientului: "; tastatura >> pacient.greutate;
		cout << "Pacientul a facut analize? (1-DA ; 0-NU) "; tastatura >> pacient.analize;
		pacient.id = new int;
		cout << "Introduceti ID-ul pacientului: "; tastatura >> *pacient.id;

		return tastatura;
	}

	bool operator<(const Pacient& pacient)
	{
		if (this->greutate < pacient.greutate)
		{
			return true;
		}
		return false;
	}

	bool operator>(const Pacient& pacient)
	{
		if (this->greutate > pacient.greutate)
		{
			return true;
		}
		return false;
	}

};

void calcul_imc(const Pacient& pacient) {
	if (pacient.analize == true) {
		cout << "Pacientul "<<pacient.nume<<" a cerut un calcul IMC si poate beneficia de el, deoarece si-a facut analizele." << endl;

		float calcul = pacient.greutate / ((pacient.inaltime/100) * (pacient.inaltime/100));
		cout << "Pacientul " << pacient.nume << " are un IMC: " << calcul << " ceea ce indica ca este in caz: ";
		if (calcul < 18.5) {
			cout << "Subponderal" << endl;
		}
		else if (18.5 <= calcul && calcul <= 24.5)
		{
			cout << "Normal" << endl;
		}
		else if (24.5 < calcul && calcul <= 30)
		{
			cout << "Supraponderal" << endl;
		}
		else if (calcul > 30)
		{
			cout << "Obez" << endl;
		}
	}
	else
	{
		cout << "Pacientul "<<pacient.nume<<" ca sa primesti un calcul IMC trebuie sa-ti faci analizele"<<endl;
	}

}

void afisare_detalii_pacient(const Pacient& pacient)
{
	cout << "Pacientul " << pacient.nume << " cu varsta " << pacient.varsta << " poate sa beneficieze de";
	if (pacient.varsta >= 18 && pacient.varsta <= 30)
	{
		cout << " reducere de student de 20% la consultatii!" << endl;
	}
	else if (pacient.varsta >= 31 && pacient.varsta <= 65)
	{
		cout << " reducere de tanar de 8% la consultatii!" << endl;
	}
	else if (pacient.varsta > 65)
	{
		cout << " reducere de pensionar de 30% la consultatii!" << endl;
	}
}

int Pacient::numar_total_pacienti = 0;

class Medicament {
private:
	string nume;
	float pret;
	int cantitate;
	const string categorie;
	static float suma_totala_preturi;
	static float TVA;
	int* cod;

public:

	Medicament() : categorie("Administrare orala")
	{
		this->nume = "Paracetamol";
		this->pret = 4.5;
		this->cantitate = 10;
		this->cod = new int(100);
		suma_totala_preturi += pret;
	}

	Medicament(string nume, const string categorie) : categorie(categorie)
	{
		this->nume = nume;
		this->pret = 7;
		this->cantitate = 10;
		this->cod = new int(101);
		suma_totala_preturi += pret;
	}

	Medicament(string nume, float pret, const string categorie) : categorie(categorie)
	{
		this->nume = nume;
		this->pret = pret;
		this->cantitate = 10;
		this->cod = new int(102);
		suma_totala_preturi += pret;
	}

	Medicament(string nume, float pret, int cantitate, int cod, const string categorie) : categorie(categorie)
	{
		this->nume = nume;
		this->pret = pret;
		this->cantitate = cantitate;
		this->cod = new int(cod);
		suma_totala_preturi += pret;
	}

	// constructorul de copiere
	Medicament(const Medicament& medi) : categorie(medi.categorie)
	{
		this->nume = medi.nume;
		this->pret = medi.pret;
		this->cantitate = medi.cantitate;
		if (this->cod != nullptr)
		{
			this->cod = new int(*medi.cod);

		}
		else
		{
			this->cod = nullptr;
		}
		suma_totala_preturi += pret;

	}

	string getNume() {
		return this->nume;
	}

	float getPret() {
		return this->pret;
	}

	int getCantitate() {
		return this->cantitate;
	}

	int getCod() {
		if (cod != nullptr)
		{
			return *this->cod;
		}
	}
	
	float getTVA() {
		return this->TVA;
	}

	void setNume(string nume) {
		this->nume = nume;
	}

	void setPret(float pret) {
		this->pret = pret;
	}

	void setCantitate(int cantitate) {
		this->cantitate = cantitate;
	}

	void setCod(int* cod) {
		if (cod != nullptr)
		{
			this->cod = cod;
		}
	}
	void setTVA(static float TVA)
	{
		this->TVA = TVA;
	}

	Medicament& operator=(const Medicament& medicament)
	{
		if (this != &medicament)
		{
			this->nume = medicament.nume;


			this->pret = medicament.pret;
			this->cantitate = medicament.cantitate;
			if (this->cod != nullptr)
			{
				this->cod = new int(*medicament.cod);

			}
			else
			{
				this->cod = nullptr;
			}
		}
		return *this;
	}
	~Medicament()
	{
		if (this->cod != NULL)
		{
			delete[] this->cod;
			this->cod = NULL;
		}
	}

	static float returnare_preturi()
	{
		return suma_totala_preturi;
	}

	void afisare_medicament() 
	{
		cout << "Codul medicamentului: " << *cod << endl;
		cout << "Numele medicamentului: " << nume << "; Categoria: " << categorie << "; Pret: " << pret << "; TVA: " << TVA << "; Cantitate: " << cantitate << endl;
	}
	
	friend ostream& operator<<(ostream& c, Medicament& medicament)
	{
		if (medicament.cod != nullptr)
		{
			cout << "Codul medicamentului: " << *medicament.cod << endl;
		}

		cout << "Numele medicamentului: " << medicament.nume << "; Categoria: " << medicament.categorie << "; Pret: " << medicament.pret << "; TVA: " << medicament.TVA << "; Cantitate: " << medicament.cantitate << endl;
		return c;
	}

	friend istream& operator>>(istream& i, Medicament& medicament)
	{
		cout << "Introduceti numele medicamentului: "; i >> medicament.nume;
		cout << "Introduceti pretul medicamentului pe pastila: "; i >> medicament.pret;
		cout << "Introduceti cantitatea medicamentului: "; i >> medicament.cantitate;
		medicament.cod = new int;
		cout << "Introduceti codul medicamentului: "; i >> *medicament.cod;

		return i;
	}

	Medicament& operator++()
	{
		this->cantitate += 10;
		return *this;
	}

	Medicament& operator--()
	{
		this->cantitate -= 5;
		return *this;
	}

	Medicament& operator++(int)
	{
		Medicament temp = *this;
		this->cantitate += 10;
		return temp;
	}

	Medicament& operator--(int)
	{
		Medicament temp = *this;
		this->cantitate -= 5;
		return temp;
	}



	friend void valoare_medicament(const Medicament& medicament);
	friend void detalii_medicament(const Medicament& medicament);
};

void valoare_medicament(const Medicament& medicament)
{
	int val = medicament.pret * medicament.cantitate;
	cout << "Medicamentul " << medicament.nume << " are valoarea totala de: " << val << " lei.";
}

void detalii_medicament(const Medicament& medicament)
{
	if (medicament.categorie == "Administrare orala")
	{
		cout << "Medicamentul " << medicament.nume << " se ia cu apa!" << endl;
	}
	else
	{
		cout << "Medicamentul " << medicament.nume << " nu se ia cu apa!" << endl;
	}
}



float Medicament::suma_totala_preturi = 0;
float Medicament::TVA = 0.05f;

class PersonalMedical {
private:
	string nume;
	float salariu;
	const string spital;
	static int numar_total_personal;
	char* specializare;
public:

	PersonalMedical() : spital("Floreasca")
	{
		this->nume = "Dr. Andra Glavan";
		this->salariu = 10250;
		this->specializare = new char[strlen("Neurologie") + 1];
		strcpy(specializare, "Neurologie");
		numar_total_personal++;
	}

	PersonalMedical(string nume, float salariu) : spital("Floreasca")
	{
		this->nume = nume;
		this->salariu = salariu;
		this->specializare = new char[strlen("Cardiologie") + 1];
		strcpy(specializare, "Cardiologie");
		numar_total_personal++;
	}

	PersonalMedical(string nume, float salariu, const char* specializare) : spital("Gaesti")
	{
		this->nume = nume;
		this->salariu = salariu;
		this->specializare = new char[strlen(specializare) + 1];
		strcpy(this->specializare, specializare);
		numar_total_personal++;
	}

	PersonalMedical(string nume, float salariu, const char* specializare, const string spital) : spital(spital)
	{
		this->nume = nume;
		this->salariu = salariu;
		this->specializare = new char[strlen(specializare) + 1];
		strcpy(this->specializare, specializare);
		numar_total_personal++;
	}

	//constructor de copiere
	PersonalMedical(const PersonalMedical& pm) : spital(pm.spital)
	{
		this->nume = pm.nume;
		this->salariu = salariu;
		if (this->specializare != nullptr)
		{
			this->specializare = new char[strlen(pm.specializare) + 1];
			strcpy(this->specializare, pm.specializare);
		}
		else
		{
			this->specializare = nullptr;
		}
		numar_total_personal++;
	}

	string getNume() {
		return this->nume;
	}
	
	float getSalariu() {
		return this->salariu;
	}

	char getSpecializare() {
		if (specializare != nullptr)
		{
			return *this->specializare;
		}
	}

	void setNume(string nume) {
		this->nume = nume;
	}

	void setSalariu(float salariu) {
		this->salariu = salariu;
	}

	void setSpecializare(char* specializare) {
		if (specializare != nullptr)
		{
			this->specializare = specializare;
		}
	}

	PersonalMedical& operator=(const PersonalMedical& pm)
	{
		if (this != &pm)
		{

			this->nume = pm.nume;
			this->salariu = salariu;
			if (this->specializare != nullptr)
			{
				this->specializare = new char[strlen(pm.specializare) + 1];
				strcpy(this->specializare, pm.specializare);
			}
			else
			{
				this->specializare = nullptr;
			}
		}
		return *this;
	}
	
	~PersonalMedical()
	{
		if (this->specializare != NULL)
		{
			delete[] this->specializare;
			this->specializare = NULL;
		}
	}

	void afisare_personal_medical()
	{
		cout << "Numele Personalului Medical: " << nume << "; Specializarea: " << specializare << "; Spitalul unde lucreaza: " << spital << "; Salariul sau: " << salariu << endl;
	}

	int static numar_personal_medical() {
		return numar_total_personal;
	}

	friend ostream& operator<<(ostream& c, PersonalMedical& pm)
	{
		cout << "Numele Personalului Medical: " << pm.nume << "; Specializarea: " << pm.specializare << "; Spitalul unde lucreaza: " << pm.spital << "; Salariul sau: " << pm.salariu << endl;
		return c;
	}

	friend istream& operator>>(istream& i, PersonalMedical& pm)
	{
		delete[] pm.specializare;
		cout << "Numele Personalului Medical: "; getline(i, pm.nume);
		cout << "Introduceti numele personalului medical: "; i >> pm.nume;
		pm.specializare = new char[100];
		cout << "Introduceti specializarea: "; i >> pm.specializare;
		cout << "Introduceti salariul: "; i >> pm.salariu;

		return i;
	}

	bool operator==(const PersonalMedical& pm)
	{
		if (this->nume != pm.nume)
		{
			return false;
		}

		if (this->specializare != pm.specializare)
		{
			return false;
		}

		if (this->salariu != pm.salariu)
		{
			return false;
		}

		return true;
	}

	bool operator!=(const PersonalMedical& pm)
	{
		return !(*this == pm);
	}

	friend void pacienti_asteptare(const PersonalMedical& pm);
	friend void afisare_sectie_personal(const PersonalMedical& pm);
};

void pacienti_asteptare(const PersonalMedical& pm)
{
	cout << "PACIENTI IN ASTEPTARE" << endl;
	if (pm.nume == "Dr. Andra Glavan")
	{
		cout << pm.nume << " are in asteptare 10 pacienti la sectia: " << pm.specializare << endl;
	}
	else if (pm.nume == "Dr. Pintilescu Bogdan")
	{
		cout << pm.nume << " are in asteptare 16 pacienti la sectia: " << pm.specializare << endl;
	}
	else
	{
		cout << pm.nume << " are liber in aceasta zi" << endl;
	}
}

void afisare_sectie_personal(const PersonalMedical& pm)
{
	cout << "Personalul medical: " << pm.nume << " trebuie sa mearga de urgenta la sectia: " << pm.specializare << endl;
}


int PersonalMedical::numar_total_personal = 0;

int main() {
	 //CLASA 1 - PACIENT
	cout << "---------- PACIENT ----------" << endl;
	cout << "" << endl;

	//vector de obiecte
	Pacient pacientii[3];
	
	pacientii[0] = Pacient();
	pacientii[1] = Pacient("Monica Mitroi", 22, "Feminin");
	pacientii[2] = Pacient("Ioana Popescu", 35, "Feminin", 1, 99, "Camera 104", 165, 59);


	//afisare vector de obiecte
	cout << "VECTOR PACIENTI" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << pacientii[i] << endl;
	}



	//matrice de obiecte
	Pacient matrice_pacienti[2][2];
	matrice_pacienti[0][0] = Pacient();
	matrice_pacienti[0][1] = Pacient();
	matrice_pacienti[1][0] = Pacient();
	matrice_pacienti[1][1] = Pacient();


	//afisare matrice de obiecte
	cout << "MATRICE PACIENTI" << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << matrice_pacienti[i][j];
		}
		cout << endl;
	}



	Pacient pacient0;
	pacient0.afisare_pacient();
	Pacient pacient1(20);
	pacient1.afisare_pacient();
	Pacient pacient2("Dinu Ana", 20, "Feminin");
	pacient2.afisare_pacient();
	Pacient pacient3("Gabriela Popa", 21, "Feminin", 1, 3, "Camera 103", 166, 55);
	pacient3.afisare_pacient();

	int x = Pacient::Numarul_Total_Al_Pacientilor();
	cout << "Numarul total de pacienti este: " << x << endl;
	cout << "" << endl;

	cout << "Constructorul de copiere: " << endl;
	Pacient pacient4 = pacient3;
	pacient4.afisare_pacient();
	cout << "" << endl;
	calcul_imc(pacient3);
	cout << "" << endl;
	afisare_detalii_pacient(pacient3);

	cout << pacient1.getNume() << endl;
	pacient1.setNume("Eva Dumitru");
	cout << pacient1.getNume() << endl;

	cout << pacient1;
	Pacient pacient5 = pacient0;
	cin >> pacient5;
	cout << pacient5;

	if (pacient1 < pacient2)
	{
		cout << "Pacientul " << pacient2.getNume()  << " are o greutate mai mare decat " << pacient1.getNume();
	}
	else
	{
		cout << "Pacientul " << pacient1.getNume() << " are o greutate mai mare decat " << pacient2.getNume();
	}

	if (pacient2 > pacient3)
	{
		cout << "Pacientul " << pacient2.getNume() << " are o greutate mai mare decat " << pacient3.getNume();
	}
	else
	{
		cout << "Pacientul " << pacient3.getNume() << " are o greutate mai mare decat " << pacient2.getNume();
	}

	cout << "" << endl;

	//CLASA 2 - MEDICAMENT
	cout << "---------- MEDICAMENTE ----------" << endl;
	cout << "" << endl;

	//vector de medicamente
	Medicament v_medicamente[3];
	v_medicamente[0] = Medicament();
	v_medicamente[1] = Medicament("Nazalist", "Administrare nazala");
	v_medicamente[2] = Medicament("Alfamil", "Administrare orala");

	//afisare vector de medicamente
	cout << "VECTOR MEDICAMENTE" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << v_medicamente[i] << endl;
	}

	Medicament medicament0;
	medicament0.afisare_medicament();
	Medicament medicament1("Bioflu", "Administrare Nazala");
	medicament1.afisare_medicament();
	Medicament medicament2("Tertensif", 3, "Administrare Sublinguala");
	medicament2.afisare_medicament();
	Medicament medicament3("Muscoril", 4, 15, 103, "Administrare intramusculara");
	medicament3.afisare_medicament();

	cout << "Suma totala a medicamentelor este: " << Medicament::returnare_preturi() << endl;

	Medicament medicament4 = medicament3;
	medicament3.afisare_medicament();

	valoare_medicament(medicament3);

	detalii_medicament(medicament3);

	cout << medicament0.getNume() << endl;
	medicament0.setNume("Parasinus Forte");
	cout << medicament0.getNume() << endl;

	cout << medicament0;
	Medicament medicament5 = medicament0;
	cin >> medicament5;
	cout << medicament5;

	cout << "Pentru medicamentul 2: ";
	cout << medicament2.getCantitate() << endl;
	Medicament medicament6 = medicament2;
	medicament6--;
	cout << medicament6 << endl;

	Medicament medicament7 = medicament3;
	cout << "Pentru medicamentul 3: ";
	cout << medicament3.getCantitate();
	 --medicament7;
	 cout << medicament7;
	 ++medicament7;
	 cout << medicament7;

	//CLASA 3 - PERSONALUL MEDICAL
	cout << "---------- PERSONAL MEDICAL ----------" << endl;
	cout << "" << endl;

	//vector de personal medical
	PersonalMedical v_personal[3];

	v_personal[0] = PersonalMedical("Dr. Cristescu Marta", 9194);
	v_personal[1] = PersonalMedical("Dr. Andreescu Alex", 6955);
	v_personal[2] = PersonalMedical("Dr. Dinca Mariana", 10000, "Patologie");

	cout << "VECTOR DE PERSONAL MEDICAL";
	for (int i = 0; i < 3; i++)
	{
		cout << v_personal[i] << endl;
	}

	PersonalMedical personal0;
	personal0.afisare_personal_medical();
	PersonalMedical personal1("Dr. Pintilescu Bogdan", 11294);
	personal1.afisare_personal_medical();
	PersonalMedical personal2("Dr. Oprea Adina", 9752, "Dermatologie");
	personal2.afisare_personal_medical();
	PersonalMedical personal3("Dr. Dumitru Eduard", 13583, "Patologie", "Floreasca");
	personal3.afisare_personal_medical();

	cout << "Numarul total de doctori este: " << PersonalMedical::numar_personal_medical() << endl;

	PersonalMedical personal4 = personal3;
	personal3.afisare_personal_medical();

	pacienti_asteptare(personal1);
	afisare_sectie_personal(personal3);

	cout << personal0.getNume() << endl;
	personal0.setNume("Dr. Ion Barbu");
	cout << personal0.getNume() << endl;

	cout << personal0;
	PersonalMedical personal5 = personal0;
	cin >> personal5;
	cout << personal5;

	if (personal1 != personal0)
	{
		cout << "Obiectele sunt diferite" << endl;
	}
	else
	{
		cout << "Obiectele sunt identice" << endl;
	}
}
