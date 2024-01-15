#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

//domeniul MedicaL

//clasa abstracta - Spital
class Spital
{
private:

	string nume;
	int numar_etaje;
	int numar_paturi;

public:
	virtual ~Spital() { }

	virtual void metodaPura() = 0;

	Spital()
	{
		this->nume = "Floreasca";
		this->numar_etaje = 6;
		this->numar_paturi = 100;
	}

	virtual int numar_pacienti() = 0;

	virtual int numar_personal() = 0;

	Spital(string nume, int numar_etaje, int numar_paturi)
	{
		this->nume = nume;
		this->numar_etaje = numar_etaje;
		this->numar_paturi = numar_paturi;
	}

	friend ostream& operator<<(ostream& consola, const Spital& sp)
	{
		consola << "Numele spitalului: "; consola << sp.nume << endl;
		consola << "Numar de etaje: "; consola << sp.numar_etaje << endl;
		consola << "Numar de paturi: "; consola << sp.numar_paturi << endl;

		return consola;
	}



};

class Pacient : public Spital
{
private:

	char* nume;
	int varsta;
	string gen;
	const string camera_consultatie;
	int id;
	bool analize;
	static int numar_total_pacienti;
	float greutate;
	float inaltime;
	static int ultimul_id;

public:

	void metodaPura() {
	}

	int numar_pacienti()
	{
		return numar_total_pacienti;
	}

	int numar_personal()
	{
		return 0;
	}

	Pacient() : camera_consultatie("Camera 100")
	{
		this->nume = new char[strlen("Andrei Ionescu") + 1];
		strcpy(this->nume, "Andrei Ionescu");
		this->varsta = 45;
		this->gen = "Masculin";
		this->id = ++ultimul_id;
		this->analize = 1;
		this->greutate = 70;
		this->inaltime = 175;
		numar_total_pacienti++;
	}

	Pacient(int varsta) : camera_consultatie("Camera 101")
	{

		this->nume = new char[strlen("Carla Popescu") + 1];
		strcpy(this->nume, "Carla Popescu");
		this->varsta = varsta;
		this->gen = "Feminin";
		this->analize = 0;
		id = ++ultimul_id;
		this->inaltime = 172;
		this->greutate = 65;
		numar_total_pacienti++;

	}

	Pacient(const char* nume, const string camera_consultatie, int varsta, string gen, bool analize, float inaltime, float greutate) : camera_consultatie(camera_consultatie)
	{

		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->varsta = varsta;
		this->gen = gen;
		this->analize = analize;
		this->id = ++ultimul_id;
		this->inaltime = inaltime;
		this->greutate = greutate;
		numar_total_pacienti++;

	}

	//constructor de copiere
	Pacient(const Pacient& p) : camera_consultatie(p.camera_consultatie)
	{
		this->nume = new char[strlen(p.nume) + 1];
		strcpy(this->nume, p.nume);
		this->varsta = p.varsta;
		this->gen = p.gen;
		this->analize = p.analize;
		this->id = p.id;
		this->inaltime = p.inaltime;
		this->greutate = p.greutate;
		numar_total_pacienti++;

	}

	//destructor
	~Pacient()
	{
		if (this->nume != NULL)
		{
			delete[] this->nume;
		}
	}

	//getteri
	char* getNume() {
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

	float getInaltime()
	{
		return this->inaltime;
	}

	float getGreutate()
	{
		return this->greutate;
	}

	int getID()
	{
		return this->id;
	}

	//setteri
	void setNume(const char* nume)
	{
		if (strlen(nume) >= 3)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else
		{
			cout << "Numele nu poate fi mai mic de 3 caractere!" << endl;
		}
	}

	void setInaltime(float inaltime)
	{
		if (inaltime >= 30)
		{
			this->inaltime = inaltime;
		}
		else
		{
			cout << "Inaltime necorespunzatoare!" << endl;
		}
	}

	void setGreutate(float greutate)
	{
		if (greutate > 0)
		{
			this->greutate = greutate;
		}
		else
		{
			cout << "Greutatea nu poate fi o valoare negativa sau 0!" << endl;
		}
	}

	void setVarsta(int varsta)
	{
		if (varsta > 0)
		{
			this->varsta = varsta;
		}
		else
		{
			cout << "Varsta nu poate fi o valoare negativa sau 0!" << endl;
		}
	}

	void setGen(string gen)
	{
		this->gen = gen;
	}

	void setAnalize(bool analize)
	{
		this->analize = analize;
	}

	void setID(int id)
	{
		if (id >= 0)
		{
			this->id = id;
		}
		else
		{
			cout << "ID-ul nu poate fi negativ!" << endl;
		}
	}

	//supraincarcarea operator=
	Pacient& operator=(const Pacient& pacient)
	{

		if (this != &pacient) //evitarea auto-asignarii
		{
			if (this->nume != NULL)
			{
				delete[] this->nume;
			}

			this->nume = new char[strlen(pacient.nume) + 1];
			strcpy(this->nume, pacient.nume);
			this->id = pacient.id;
			this->varsta = pacient.varsta;
			this->gen = pacient.gen;
			this->analize = pacient.analize;
			this->inaltime = pacient.inaltime;
			this->greutate = pacient.greutate;

		}
		return *this;

	}

	//metoda de afisare a datelor unui pacient
	void afisare_pacient() {
		cout << "ID Pacient: " << id << endl;
		cout << "Nume Pacient: " << nume << endl;
		cout << "Varsta pacient: " << varsta << endl;
		cout << "Inaltime: " << inaltime << endl;
		cout << "Greutate: " << greutate << endl;
		cout << "Genul pacientului: " << gen << endl;
		cout << "Camera de consultatie: " << camera_consultatie << endl;
		cout << "Are analizele facute?: ";
		if (this->analize == true)
		{
			cout << "DA" << endl;
		}
		else
		{
			cout << "NU" << endl;
		}

	}

	//metoda statica de afisare a numarului total de pacienti
	static int afisare_numar_total_pacienti()
	{
		return numar_total_pacienti;
	}

	//supraincarcarea operatorul <<
	friend ostream& operator<<(ostream& consola, const Pacient& pacient)
	{
		consola << "ID pacient: " << pacient.id << endl;
		consola << "Nume pacient: " << pacient.nume << endl;
		consola << "Varsta pacient: " << pacient.varsta << endl;
		consola << "Inaltime: " << pacient.inaltime << endl;
		consola << "Greutate: " << pacient.greutate << endl;
		consola << "Genul pacientului: " << pacient.gen << endl;
		consola << "Camera de consultatie: " << pacient.camera_consultatie << endl;
		consola << "Are analizele facute?: ";
		if (pacient.analize == true)
		{
			consola << "DA" << endl;
		}
		else
		{
			consola << "NU" << endl;
		}

		return consola;
	}

	//operatorul << pentru fisiere text! (scriem in fisierul text)
	friend ofstream& operator<<(ofstream& out, const Pacient& p) {
		out << p.nume << "\n";
		out << p.varsta << "\n";
		out << p.gen << "\n";
		out << p.inaltime << "\n";
		out << p.greutate << "\n";
		out << p.analize << "\n";
		out << p.id << "\n";
		return out;
	}

	//supraincarcarea operatorului >>
	friend istream& operator>>(istream& tastatura, Pacient& pacient)
	{
		int idManual;
		cout << "Introduceti ID-ul pacientului (sau 0 pentru a utiliza urmatorul ID disponibil): "; tastatura >> idManual;
		if (idManual == 0)
		{
			pacient.id = ++ultimul_id;
		}
		else
		{
			pacient.id = idManual;
		}

		if (pacient.nume != NULL)
		{
			delete[] pacient.nume;
		}

		pacient.nume = new char[100];
		cout << "Introduceti numele pacientului: ";
		tastatura.ignore(); // ignora newline ul de la ID
		tastatura.getline(pacient.nume, 100);
		cout << "Introduceti varsta pacientului: "; tastatura >> pacient.varsta;
		cout << "Introduceti genul pacientului: "; tastatura >> pacient.gen;
		cout << "Introduceti inaltimea pacientului: "; tastatura >> pacient.inaltime;
		cout << "Introduceti greutatea pacientului: "; tastatura >> pacient.greutate;
		cout << "Pacientul a facut analize? (1-DA ; 0-NU) "; tastatura >> pacient.analize;

		return tastatura;
	}

	//operatorul >> pentru fisiere text! (citim din fisierul text)
	friend ifstream& operator>>(ifstream& in, Pacient& p)
	{
		char aux[100];// citesc numele cu getline si aloc memorie
		in.getline(aux, 100);
		if (p.nume != nullptr)
		{
			delete[] p.nume;
		}
		p.nume = new char[strlen(aux) + 1];
		strcpy(p.nume, aux);
		in >> p.varsta;
		in.ignore(); // ignoram newline ul
		getline(in, p.gen);
		in >> p.analize;
		in >> p.greutate;
		in >> p.inaltime;

		return in;

	}

	//supraincarcarea operatorului <, care compara greutatea a doi pacienti
	bool operator<(const Pacient& pacient)
	{

		if (this->greutate < pacient.greutate)
		{
			return true;
		}
		return false;

	}

	//supraincarcarea operatorului >, care compara varsta a doi pacienti
	bool operator>(const Pacient& pacient)
	{

		if (this->varsta > pacient.varsta)
		{
			return true;
		}
		return false;

	}

	friend void calcul_imc(const Pacient& pacient);
	friend void reducere(const Pacient& pacient);
};
int Pacient::numar_total_pacienti = 0;
int Pacient::ultimul_id = 0;

void calcul_imc(const Pacient& pacient)
{

	if (pacient.analize == true)
	{

		float calcul = pacient.greutate / ((pacient.inaltime / 100) * (pacient.inaltime / 100));

		cout << "Pacientul [" << pacient.nume << "] are un IMC: " << calcul << " ceea ce indica ca este in caz: ";
		if (calcul < 18.5)
		{
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
		cout << "Pacientul " << pacient.nume << " nu poate primi un calcul IMC, deoarece nu are analizele facute." << endl;
	}

}
void reducere(const Pacient& pacient)
{
	if (pacient.varsta <= 18)
	{
		cout << "Pacientul [" << pacient.nume << "] poate beneficia de reducere la consultatii de 8%" << endl;
	}
	else if (pacient.varsta > 18 && pacient.varsta <= 30)
	{
		cout << "Pacientul [" << pacient.nume << "] poate beneficia de reducere la consultatii de 5%" << endl;
	}
	else if (pacient.varsta > 30 && pacient.varsta <= 65)
	{
		cout << "Pacientul [" << pacient.nume << "] poate beneficia de reducere la consultatii de 3%" << endl;
	}
	else if (pacient.varsta > 65)
	{
		cout << "Pacientul [" << pacient.nume << "] poate beneficia de reducere la consultatii de 12%" << endl;
	}
}

//relatia de is-a (mostenire)
class DetaliiSanatate : public Pacient
{
private:

	int nrConsultatii;
	int* frecventaCardiaca;
	int nivelZaharSange; //masurata in mg / dL
	int sistolica;
	int diastolica;

public:

	DetaliiSanatate() : Pacient()
	{
		this->nrConsultatii = 3;
		this->frecventaCardiaca = new int[this->nrConsultatii];
		for (int i = 0; i < this->nrConsultatii; i++)
		{
			this->frecventaCardiaca[i] = 80 + (i * 3);
		}
		this->nivelZaharSange = 75;
		this->sistolica = 120;
		this->diastolica = 80;
	}

	DetaliiSanatate(int nrConsultatii, int* frecventa, int nivelZaharSange, int sistolica, int diastolica, const char* nume, const string camera_consultatie, int varsta, string gen, bool analize, float inaltime, float greutate) : Pacient(nume, camera_consultatie, varsta, gen, analize, inaltime, greutate)
	{

		this->nrConsultatii = nrConsultatii;
		this->frecventaCardiaca = new int[this->nrConsultatii];
		for (int i = 0; i < this->nrConsultatii; i++)
		{
			this->frecventaCardiaca[i] = frecventa[i];
		}
		this->nivelZaharSange = nivelZaharSange;
		this->sistolica = sistolica;
		this->diastolica = diastolica;

	}

	//constructor de copiere
	DetaliiSanatate(const DetaliiSanatate& ds) : Pacient(ds)
	{

		this->nrConsultatii = ds.nrConsultatii;
		this->frecventaCardiaca = new int[this->nrConsultatii];
		for (int i = 0; i < this->nrConsultatii; i++)
		{
			this->frecventaCardiaca[i] = ds.frecventaCardiaca[i];
		}
		this->nivelZaharSange = ds.nivelZaharSange;
		this->sistolica = ds.sistolica;
		this->diastolica = ds.diastolica;

	}

	//destructor
	~DetaliiSanatate()
	{
		if (this->frecventaCardiaca != NULL)
		{
			delete[] this->frecventaCardiaca;
		}
	}

	//operator=
	DetaliiSanatate& operator=(DetaliiSanatate& ds)
	{
		if (this != &ds)
		{
			Pacient::operator=(ds); //apelarea operatorului = din clasa Pacient
			this->nrConsultatii = ds.nrConsultatii;
			if (this->frecventaCardiaca != NULL)
			{
				delete[] this->frecventaCardiaca;
			}
			this->frecventaCardiaca = new int[this->nrConsultatii];
			for (int i = 0; i < this->nrConsultatii; i++)
			{
				this->frecventaCardiaca[i] = ds.frecventaCardiaca[i];
			}
			this->nivelZaharSange = ds.nivelZaharSange;
			this->sistolica = ds.sistolica;
			this->diastolica = ds.diastolica;
		}

		return *this;
	}


	//operatorul << de afisare
	friend ostream& operator<<(ostream& out, const DetaliiSanatate& ds)
	{

		out << (Pacient&)ds; //si pentru pacient
		out << "Numarul de consultatii: " << ds.nrConsultatii << endl;
		out << "Frecventa cardiaca: ";
		for (int i = 0; i < ds.nrConsultatii - 1; i++)
		{
			cout << ds.frecventaCardiaca[i] << ", ";
		}
		cout << ds.frecventaCardiaca[ds.nrConsultatii - 1] << endl;
		out << "Nivelul de zahar din sange (mg/dL): " << ds.nivelZaharSange << endl;
		out << "Sistolica tensiunii arteriale: " << ds.sistolica << endl;
		out << "Diastolica tensiunii arteriale: " << ds.diastolica << endl;

		return out;

	}

	//get-eri
	int getNrConsultatii()
	{
		return this->nrConsultatii;
	}

	int* getFrecventa()
	{
		return this->frecventaCardiaca;
	}

	int getNivelZahar()
	{
		return this->nivelZaharSange;
	}

	int getSistolica()
	{
		return this->sistolica;
	}

	int getDiastolica()
	{
		return this->diastolica;
	}

	//set-eri
	void setNrConsultatii(int nrConsultatii)
	{
		this->nrConsultatii = nrConsultatii;
	}

	void setFrecventa(int nrConsultatii, int* frecventaCardiaca)
	{
		if (nrConsultatii > 0)
		{
			this->nrConsultatii = nrConsultatii;
			if (this->frecventaCardiaca != NULL)
			{
				delete[] this->frecventaCardiaca;
			}
			this->frecventaCardiaca = new int[this->nrConsultatii];
			for (int i = 0; i < this->nrConsultatii; i++)
			{
				this->frecventaCardiaca[i] = frecventaCardiaca[i];
			}
		}
		else
		{
			this->nrConsultatii = 0;
			this->frecventaCardiaca = NULL;
		}
	}

	void setNivelZahar(int nivelZaharSange)
	{
		if (nivelZaharSange > 0)
		{
			this->nivelZaharSange = nivelZaharSange;
		}
		else
		{
			cerr << "Nivel zahar din sange invalid!" << endl;
		}
	}

	void setSistolica(int sistolica)
	{
		if (sistolica > 0)
		{
			this->sistolica = sistolica;
		}
		else
		{
			cerr << "Nivel de sistolica invalida!" << endl;
		}
	}

	void setDiastolica(int diastolica)
	{
		if (diastolica > 0)
		{
			this->diastolica = diastolica;
		}
		else
		{
			cerr << "Nivel de diastolica invalida!" << endl;
		}
	}

	//metoda calcularea frecventei cardiace medie a pacientului
	float calculareFrecventaMedie()
	{
		if (nrConsultatii == 0) {
			cerr << "Nu exista consultatii pentru calcularea frecventei cardiace medii!" << endl;
			return 0.0;
		}

		int sumaFrecvente = 0;
		for (int i = 0; i < nrConsultatii; i++) {
			sumaFrecvente += frecventaCardiaca[i];
		}

		float x = sumaFrecvente / (float)nrConsultatii;
		cout << "Frecventa medie este: " << x << endl;
		cout << "" << endl;
		cout << "Detalii despre frecventa cardiaca: " << endl;
		cout << "" << endl;
		if (x < 70)
		{
			cout << "Nivelul mediu al frecventei cardiace indica tahicardie. Consultati medicul!" << endl;
		}
		else if (x >= 70 && x <= 80)
		{
			cout << "Nivelul mediu al frecventei cardiace indica o stare normala. Felicitari!" << endl;
		}
		else if (x > 80)
		{
			cout << "Nivelul mediu al frecventei cardiace indica brahicardie. Consultati medicul!" << endl;
		}
	}

	friend void detaliiNivelZahar(const DetaliiSanatate& ds);
};

void detaliiNivelZahar(const DetaliiSanatate& ds)
{
	cout << "Detalii despre nivelul zaharului din sange:" << endl;
	cout << "Nivelul actual: " << ds.nivelZaharSange << " mg/dL" << endl;

	if (ds.nivelZaharSange < 70) {
		cout << "Nivel scazut de zahar in sange. Consultati medicul!" << endl;
	}
	else if (ds.nivelZaharSange >= 70 && ds.nivelZaharSange <= 80) {
		cout << "Nivel normal de zahar in sange." << endl;
	}
	else {
		cout << "Nivel crescut de zahar in sange. Consultati medicul!" << endl;
	}
}

//clasa abstracta - Laborator
class Laborator
{
private:

	string nume;
	int numar_substante;
	int numar_medicamente_realizate;

public:

	virtual ~Laborator() {}

	virtual void metodaPura() = 0;

	Laborator()
	{
		this->nume = "Laboratorul National";
		this->numar_substante = 40000;
		this->numar_medicamente_realizate = 250000;
	}

	virtual double valori_medicamente() = 0;

	Laborator(string nume, int numar_substante, int numar_medicamente_realizate)
	{
		this->nume = nume;
		this->numar_substante = numar_substante;
		this->numar_medicamente_realizate = numar_medicamente_realizate;
	}

	friend ostream& operator<<(ostream& out, const Laborator& l)
	{
		out << l.nume << endl;
		out << l.numar_substante << endl;
		out << l.numar_medicamente_realizate << endl;

		return out;

	}

};

class Medicament : public Laborator
{
private:

	char* nume;
	float pret;
	int cantitate_ceruta; //cantitatea ceruta pe cutie
	const string grupa_farmaceutica;
	static float suma_totala_preturi;
	static float TVA;
	static int ultimul_cod;
	bool stoc;
	int cod;

public:

	void metodaPura()
	{
		cout << "Metoda pura" << endl;
	}

	double valori_medicamente()
	{
		return pret * cantitate_ceruta;
	}

	Medicament() : grupa_farmaceutica("Analgezic")
	{

		this->nume = new char[strlen("Nurofen Express") + 1];
		strcpy(this->nume, "Nurofen Express");
		this->pret = 35.5;
		this->cantitate_ceruta = 2;
		this->stoc = 1;
		this->cod = ++ultimul_cod;
		suma_totala_preturi += this->pret;

	}

	Medicament(float pret) : grupa_farmaceutica("Analgezic")
	{

		this->nume = new char[strlen("Panadol") + 1];
		strcpy(this->nume, "Panadol");
		this->pret = pret;
		this->cantitate_ceruta = 3;
		this->stoc = 1;
		this->cod = ++ultimul_cod;
		suma_totala_preturi += pret;

	}

	Medicament(const char* nume, float pret, int cantitate_ceruta, const string grupa, bool stoc) : grupa_farmaceutica(grupa)
	{

		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->pret = pret;
		this->cantitate_ceruta = cantitate_ceruta;
		this->stoc = stoc;
		this->cod = ++ultimul_cod;
		suma_totala_preturi += pret;

	}

	//constructorul de copiere
	Medicament(const Medicament& med) : grupa_farmaceutica(med.grupa_farmaceutica)
	{

		this->nume = new char[strlen(med.nume) + 1];
		strcpy(this->nume, med.nume);
		this->pret = med.pret;
		this->cantitate_ceruta = med.cantitate_ceruta;
		this->stoc = med.stoc;
		this->cod = med.cod;
		suma_totala_preturi += pret;
	}

	//destructor
	~Medicament()
	{
		if (this->nume != NULL)
		{
			delete[] this->nume;
		}
	}

	//supraincarcarea operator=
	Medicament& operator=(const Medicament& medicament)
	{
		if (this != &medicament)
		{
			if (this->nume != NULL)
			{
				delete[] this->nume;
			}
			this->nume = new char[strlen(medicament.nume) + 1];
			strcpy(this->nume, medicament.nume);
			this->pret = medicament.pret;
			this->cantitate_ceruta = medicament.cantitate_ceruta;
			this->stoc = medicament.stoc;
			this->cod = medicament.cod;
		}

		suma_totala_preturi += medicament.pret;

		return *this;
	}

	// get-eri
	char* getNume()
	{
		return this->nume;
	}

	float getPret()
	{
		return this->pret;
	}

	int getCantitate()
	{
		return this->cantitate_ceruta;
	}

	bool getStoc()
	{
		return this->stoc;
	}

	int getCod()
	{
		return this->cod;
	}

	//set-eri
	void setNume(const char* nume)
	{
		if (strlen(nume) >= 3)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else
		{
			cout << "Numele nu poate fi mai mic de 3 caractere!" << endl;
		}
	}

	void setPret(float pret)
	{
		if (pret > 0)
		{
			this->pret = pret;
		}
		else
		{
			cout << "Pretul unui medicament nu poate fi negativ sau 0!" << endl;
		}
	}

	void setCantitate(int cantitate_ceruta)
	{
		if (cantitate_ceruta > 0)
		{
			this->cantitate_ceruta = cantitate_ceruta;
		}
		else
		{
			cout << "Cantitatea ceruta nu poate fi negativa sau 0!" << endl;
		}
	}

	void setCod(int cod)
	{
		if (cod >= 0)
		{
			this->cod = cod;
		}
		else
		{
			cout << "Cod necorespunzator!" << endl;
		}
	}

	void setStoc(bool stoc)
	{
		this->stoc = stoc;
	}

	void afisare_medicament()
	{
		cout << "Codul medicamentului: " << cod << endl;
		cout << "Numele medicamentului: " << nume << endl;
		cout << "Pretul medicamentului: " << pret << endl;
		cout << "TVA: " << TVA * 100 << "%" << endl;
		cout << "Cantitatea ceruta a medicamentului: " << cantitate_ceruta << endl;
		cout << "Medicamentul se afla in stoc?: ";
		if (stoc == 1)
		{
			cout << "DA" << endl;

		}
		else
		{
			cout << "NU" << endl;
		}
	}

	//metoda statica
	static int returnare_suma_totala()
	{
		return suma_totala_preturi;
	}

	//supraincarcarea operatorului <<
	friend ostream& operator<<(ostream& c, const Medicament& medicament)
	{
		c << "Codul medicamentului: " << medicament.cod << endl;
		c << "Numele medicamentului: " << medicament.nume << endl;
		c << "Grupa farmaceutica: " << medicament.grupa_farmaceutica << endl;
		c << "Pret: " << medicament.pret << endl;
		c << "TVA: " << medicament.TVA * 100 << "%" << endl;
		c << "Cantitate: " << medicament.cantitate_ceruta << endl;
		cout << "Medicamentul se afla in stoc?: ";
		if (medicament.stoc == 1)
		{
			cout << "DA" << endl;

		}
		else
		{
			cout << "NU" << endl;
		}

		return c;
	}

	//supraincarcarea operatorului << pentru fisiere text (scriere)
	friend ofstream& operator<<(ofstream& out, Medicament& medicament)
	{
		out << medicament.cod << "\n";
		out << medicament.nume << "\n";
		out << medicament.pret << "\n";
		out << medicament.cantitate_ceruta << "\n";
		out << medicament.stoc << "\n";

		return out;

	}

	//supraincarcarea operatorului >>
	friend istream& operator>>(istream& i, Medicament& medicament)
	{
		int codManual;
		cout << "Introduceti COD-ul medicamentului (sau 0 pentru a utiliza urmatorul COD disponibil): "; i >> codManual;
		if (codManual == 0)
		{
			medicament.cod = ++ultimul_cod;
		}
		else
		{
			medicament.cod = codManual;
		}

		medicament.nume = new char[100];
		cout << "Introduceti numele medicamentului: ";
		i.ignore(); // ignora newline ul de la COD 
		i.getline(medicament.nume, 100);
		cout << "Introduceti pretul medicamentului: "; i >> medicament.pret;
		cout << "Introduceti cantitatea ceruta a medicamentului: "; i >> medicament.cantitate_ceruta;
		cout << "Medicamentul se afla in stoc? (1-DA, 0-NU): "; i >> medicament.stoc;

		return i;

	}

	//supraincarcarea operatorului >> pentru fisiere text (citire)
	friend ifstream& operator>>(ifstream& in, Medicament& medicament)
	{
		in >> medicament.cod;
		in.ignore();
		char aux[100]; // aloc memorie pentru nume;
		in.getline(aux, 100);
		if (medicament.nume != NULL)
		{
			delete[] medicament.nume;
		}
		medicament.nume = new char[strlen(aux) + 1];
		strcpy(medicament.nume, aux);
		in >> medicament.pret;
		in >> medicament.cantitate_ceruta;
		in >> medicament.stoc;

		return in;

	}

	//supraincarcarea operatorului ++ care creste cantitatea ceruta cu 5
	Medicament& operator++()
	{
		this->cantitate_ceruta += 5;
		return *this;
	}

	//supraincarcarea operatorului -- care scade cantitatea ceruta cu 1
	Medicament& operator--()
	{
		this->cantitate_ceruta -= 1;
		return *this;
	}

	//supraincarcarea operatorului ++ si -- post
	Medicament operator++(int)
	{
		Medicament temp = *this;
		this->cantitate_ceruta += 5;
		return temp;
	}

	Medicament operator--(int)
	{
		Medicament temp = *this;
		this->cantitate_ceruta -= 1;
		return temp;
	}

	friend void valoare_medicament(const Medicament& medicament);
	friend void efecte_secundare(const Medicament& medicament);

};

float Medicament::suma_totala_preturi = 0;
int Medicament::ultimul_cod = 0;
float Medicament::TVA = 0.05;

void valoare_medicament(const Medicament& medicament)
{
	float valCuTVA = medicament.pret * medicament.cantitate_ceruta * (1 + medicament.TVA);
	float valFaraTVA = medicament.pret * medicament.cantitate_ceruta;

	cout << "Medicamentul [" << medicament.nume << "] are valoarea totala cu TVA de: " << valCuTVA << " lei." << endl;
	cout << "Medicamentul [" << medicament.nume << "] are valoarea totala fara TVA de: " << valFaraTVA << " lei." << endl;
	cout << "" << endl;
}

void efecte_secundare(const Medicament& medicament)
{
	cout << "Detalii despre efectele secundare ale medicamentului [" << medicament.nume << "]: " << endl;

	if (medicament.grupa_farmaceutica == "Analgezic")
	{
		cout << "Medicamentul face parte din grupa analgezicelor." << endl;
		cout << "Efecte secundare: Pot aparea alergii, senzatii de greata sau dureri de cap. " << endl;
	}
	else if (medicament.grupa_farmaceutica == "Antibiotic")
	{
		cout << "Medicamentul face parte din grupa antibioticelor." << endl;
		cout << "Efecte secundare: Senzatii de greata sau eruptii cutanate." << endl;
	}
	else if (medicament.grupa_farmaceutica == "Antihipertensiv")
	{
		cout << "Medicamentul face parte din grupa antihipertensivelor." << endl;
		cout << "Efecte secundare: Poate sa apara bradicardie, oboseala sau chiar depresie." << endl;
	}
	else if (medicament.grupa_farmaceutica == "Diuretic")
	{
		cout << "Medicamentul face parte din grupa diureticelor." << endl;
		cout << "Efecte secundare: Poate provoca hipotensiune arteriala sau ameteli." << endl;
	}
	else if (medicament.grupa_farmaceutica == "Anticoagulant")
	{
		cout << "Medicamentul face parte din grupa anticoagulantelor." << endl;
		cout << "Efecte secundare: Senzatii de greata sau alergii." << endl;
	}
	else
	{
		cout << "Ne pare rau, dar pentru acest medicament nu avem detalii despre efectele secundare!" << endl;
	}
}

//relatia de has-a
class Farmacie {
private:
	string numeFarmacie;
	Medicament modelMedicament;
	string contactTelefon;
	string adresa;
	bool tensiuneArteriala;
public:

	Farmacie()
	{

		this->numeFarmacie = "Catena";
		this->adresa = "Strada Soarelui";
		this->contactTelefon = "07100100";
		this->tensiuneArteriala = 1;

	}

	Farmacie(string numeFarmacie, const Medicament& medicament)
	{

		this->numeFarmacie = numeFarmacie;
		this->adresa = "Bulevardul Unirii";
		this->contactTelefon = "03452100";
		this->tensiuneArteriala = 1;
		this->modelMedicament = medicament;

	}

	Farmacie(string numeFarmacie, string contact, string adresa, bool tensiune, const Medicament& medicament)
	{

		this->numeFarmacie = numeFarmacie;
		this->contactTelefon = contact;
		this->adresa = adresa;
		this->tensiuneArteriala = tensiune;
		this->modelMedicament = medicament;

	}

	//constructor de copiere
	Farmacie(const Farmacie& f)
	{
		this->numeFarmacie = f.numeFarmacie;
		this->contactTelefon = f.contactTelefon;
		this->adresa = f.adresa;
		this->tensiuneArteriala = f.tensiuneArteriala;
		this->modelMedicament = f.modelMedicament;
	}

	//operatorul =
	Farmacie& operator=(const Farmacie& f)
	{
		if (this != &f)
		{
			this->numeFarmacie = f.numeFarmacie;
			this->contactTelefon = f.contactTelefon;
			this->adresa = f.adresa;
			this->tensiuneArteriala = f.tensiuneArteriala;
		}

		return *this;
	}

	string getNumeFarmacie()
	{

		return this->numeFarmacie;

	}

	string getContactTelefon()
	{

		return this->contactTelefon;

	}

	string getAdresa()
	{

		return this->adresa;

	}

	bool getTensiune()
	{

		return this->tensiuneArteriala;

	}

	void setTelefon(string telefon)
	{

		this->contactTelefon = telefon;

	}

	void setAdresa(string adresa)
	{

		this->adresa = adresa;

	}

	void setTensiune(bool tensiune)
	{

		this->tensiuneArteriala = tensiune;

	}

	void setMedicament(const Medicament& medicament)
	{
		this->modelMedicament = medicament;
	}

	friend ostream& operator<<(ostream& consola, Farmacie& farmacie)
	{

		consola << "Nume farmacie: " << farmacie.numeFarmacie << endl;
		consola << "Adresa farmaciei: " << farmacie.adresa << endl;
		consola << "Numar de telefon: " << farmacie.contactTelefon << endl;
		if (farmacie.tensiuneArteriala == 1)
		{
			consola << "Farmacia beneficiaza de consultare gratuita a tensiunii arteriale!" << endl;
		}
		else
		{
			consola << "Din pacate, farmacia nu ofera consultare gratuita a tensiunii arteriale." << endl;
		}
		consola << "Informatii medicament: " << farmacie.modelMedicament << endl;

		return consola;

	}

	friend istream& operator>>(istream& tast, Farmacie& farmacie)
	{

		cout << "Introduceti numele farmaciei: "; tast >> farmacie.numeFarmacie;
		cout << "Introduceti adresa farmaciei: "; tast >> farmacie.adresa;
		cout << "Introduceti numarul de telefon al farmaciei: "; tast >> farmacie.contactTelefon;
		cout << "Introduceti 1 daca farmacia beneficiaza de consultare a tensiunii arteriale, altfel 0: "; tast >> farmacie.tensiuneArteriala;

		return tast;

	}

	void afisareMedicamentDinFarmacie()
	{
		if (modelMedicament.getStoc() == true)
		{
			cout << "Medicamentul [" << modelMedicament.getNume() << "] se afla in stocul farmaciei [" << numeFarmacie << "] de la adresa [" << adresa << "]";
		}
		else
		{
			cout << "Medicamentul [" << modelMedicament.getNume() << "] NU se afla in stocul farmaciei [" << numeFarmacie << "] de la adresa [" << adresa << "]";

		}
	}

	bool operator!=(const Farmacie& farmacie)
	{
		if (this->tensiuneArteriala != farmacie.tensiuneArteriala)
		{
			return true;
		}
		else if (farmacie.tensiuneArteriala != this->tensiuneArteriala)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//scrierea in fisierele binare
	//serializare - transformarea unui obiect intr-o secventa de biti
	void scrieInBinar(string numeFisier)
	{
		ofstream f(numeFisier, ios::out | ios::binary);
		if (f.is_open())
		{
			int lungNume = this->numeFarmacie.size(); //lungimea sirului de caractere
			f.write((char*)&lungNume, sizeof(lungNume)); //o scriem
			f.write(this->numeFarmacie.c_str(), lungNume + 1);

			int lungAdresa = this->adresa.size();
			f.write((char*)&lungAdresa, sizeof(lungAdresa));
			f.write(this->adresa.c_str(), lungAdresa + 1);

			int lungContact = this->contactTelefon.size();
			f.write((char*)&lungContact, sizeof(lungContact));
			f.write(this->contactTelefon.c_str(), lungContact + 1);

			f.write((char*)&this->tensiuneArteriala, sizeof(this->tensiuneArteriala));

			f.close();

			cout << "Datele au fost scrise cu succes in fisierul binar!" << endl;
		}
		else
		{
			cout << "Eroare la deschiderea fisierului!" << endl;
		}
	}

	//citirea din fisierul binar, numita deserializare - restaurarea unui obiect dintr-o secventa de biti
	void citesteDinBinar(string numeFisier)
	{
		ifstream f(numeFisier, ios::in | ios::binary);
		if (f.is_open())
		{
			//citirea stringului in fisierul binar:
			int lungNume = 0; //initializam lungimea numelui cu 0
			f.read((char*)&lungNume, sizeof(lungNume));
			char* aux = new char[lungNume + 1]; //alocam memorie pentru numele farmaciei
			f.read(aux, lungNume + 1);
			this->numeFarmacie = aux;
			delete[] aux;

			int lungAdresa = 0;
			f.read((char*)&lungAdresa, sizeof(lungAdresa));
			char* aux2 = new char[lungAdresa + 1];
			f.read(aux2, lungAdresa + 1);
			this->adresa = aux2;
			delete[] aux2;

			int lungContact = 0;
			f.read((char*)&lungContact, sizeof(lungContact));
			char* aux3 = new char[lungContact + 1];
			f.read(aux3, lungContact + 1);
			this->contactTelefon = aux3;
			delete[] aux3;

			f.read((char*)&this->tensiuneArteriala, sizeof(this->tensiuneArteriala));

			f.close();

			cout << "" << endl;
			cout << "Datele au fost citite cu succes din fisierul binar!" << endl;
		}
		else
		{
			cout << "Eroare la deschiderea fisierului!" << endl;
		}
	}


};

class PersonalMedical : public Spital
{
private:

	string nume;
	float salariu;
	const string tipContract;
	int nr_ore_lucrate;
	static int numar_total_personal;
	char* specializare;

public:

	void metodaPura()
	{
		cout << "Metoda pura" << endl;
	}

	int numar_personal()
	{
		return numar_total_personal;
	}

	int numar_pacienti() {
		return 0;
	}

	PersonalMedical() : tipContract("Perioada determinata")
	{

		this->nume = "Dr. Andra Glavan";
		this->salariu = 10250;
		this->nr_ore_lucrate = 140;
		this->specializare = new char[strlen("Neurologie") + 1];
		strcpy(specializare, "Neurologie");
		numar_total_personal++;

	}

	PersonalMedical(string nume, float salariu) : tipContract("Perioada determinata")
	{

		this->nume = nume;
		this->salariu = salariu;
		this->specializare = new char[strlen("Cardiologie") + 1];
		strcpy(specializare, "Cardiologie");
		this->nr_ore_lucrate = 93;
		numar_total_personal++;

	}

	PersonalMedical(string nume, float salariu, const string tipContract, const char* specializare, int nr_ore_lucrate) : tipContract(tipContract)
	{

		this->nume = nume;
		this->salariu = salariu;
		this->specializare = new char[strlen(specializare) + 1];
		strcpy(this->specializare, specializare);
		this->nr_ore_lucrate = nr_ore_lucrate;
		numar_total_personal++;

	}

	//constructor de copiere
	PersonalMedical(const PersonalMedical& pm) : tipContract(pm.tipContract)
	{
		this->nume = pm.nume;
		this->salariu = pm.salariu;
		this->specializare = new char[strlen(pm.specializare) + 1];
		strcpy(this->specializare, pm.specializare);
		this->nr_ore_lucrate = pm.nr_ore_lucrate;
		numar_total_personal++;
	}

	//destructor
	~PersonalMedical()
	{
		if (this->specializare != NULL)
		{
			delete[] this->specializare;
		}
	}

	//get-eri
	string getNume()
	{
		return this->nume;
	}

	float getSalariu()
	{
		return this->salariu;
	}

	char* getSpecializare()
	{
		return this->specializare;
	}

	const string getContract()
	{
		return this->tipContract;
	}

	int getNrOre()
	{
		return this->nr_ore_lucrate;
	}

	//set-eri
	void setNume(string nume)
	{
		this->nume = nume;
	}

	void setSalariu(float salariu) {
		if (salariu >= 1000)
		{
			this->salariu = salariu;
		}
		else
		{
			cout << "Salariul este prea mic!" << endl;
		}
	}

	void setSpecializare(const char* specializare) {

		if (strlen(specializare) >= 3)
		{
			this->specializare = new char[strlen(specializare) + 1];
			strcpy(this->specializare, specializare);
		}
		else
		{
			cout << "Specializare invalida!" << endl;
		}
	}

	void setNrOre(int nr_ore_lucrate)
	{
		if (nr_ore_lucrate >= 0)
		{
			this->nr_ore_lucrate = nr_ore_lucrate;
		}
		else
		{
			cout << "Numar de ore invalid!" << endl;
		}
	}


	//operator=
	PersonalMedical& operator=(const PersonalMedical& pm)
	{
		if (this != &pm)
		{
			if (this->specializare != NULL)
			{
				delete[] this->specializare;
			}
			this->specializare = new char[strlen(pm.specializare) + 1];
			strcpy(this->specializare, pm.specializare);
			this->nume = pm.nume;
			this->salariu = pm.salariu;
			this->nr_ore_lucrate = pm.nr_ore_lucrate;
		}
		return *this;
	}

	//metoda de afisare
	void afisare_personal_medical()
	{
		cout << "Numele cadrului medical: " << nume << endl;
		cout << "Tipul de contract: " << tipContract << endl;
		if (this->specializare != nullptr)
		{
			cout << "Specializarea: " << specializare << endl;
		}
		else
		{
			cout << "Specializare indisponibila!";
		}
		cout << "Numarul de ore lucrate: " << nr_ore_lucrate << endl;
		cout << "Salariul pe care il are: " << salariu << endl;
	}

	//metoda statica
	int static numar_personal_medical() {
		return numar_total_personal;
	}

	//operatorul <<
	friend ostream& operator<<(ostream& c, PersonalMedical& pm)
	{
		c << "Numele cadrului medical: " << pm.nume << endl;
		c << "Tipul de contract: " << pm.tipContract << endl;
		c << "Specializarea: " << pm.specializare << endl;
		c << "Numarul de ore lucrate: " << pm.nr_ore_lucrate << endl;
		c << "Salariul cadrului medical: " << pm.salariu << endl;
		return c;
	}

	//metoda pentru fisierele BINARE (scriere)
	//serializare - transformarea obiectului intr-o secventa de biti
	void scriereInBinar(string numeFisier)
	{
		ofstream f(numeFisier, ios::out | ios::binary);
		if (f.is_open()) {		//scrierea unui string in fisier binar:
			int lungNume = this->nume.size(); //lungimea stringului nume
			f.write((char*)&lungNume, sizeof(lungNume));
			f.write(this->nume.c_str(), lungNume + 1);
			//c_str() - transforma un string intr-un vector de caractere (const char*)
			//scrierea char* in fisier binar:
			int lungSpecializare = strlen(this->specializare);
			f.write((char*)&lungSpecializare, sizeof(lungSpecializare));
			f.write(this->specializare, lungSpecializare + 1);
			f.write((char*)&nr_ore_lucrate, sizeof(this->nr_ore_lucrate));
			f.write((char*)&this->salariu, sizeof(this->salariu));

			f.close();

			cout << "Datele personalului medical au fost introduse cu succes in fisierul binar!" << endl;
			cout << "" << endl;
		}
		else
		{
			cout << "Eroare la deschiderea fisierului." << endl;
		}
	}

	//metoda pentru fisierele BINARE (citire)
	//deserializare -> restaurarea unui obiect dintr-o secventa de biti
	void citesteInBinar(string numeFisier)
	{
		ifstream f(numeFisier, ios::out | ios::binary);
		if (f.is_open()) //verificam daca fisierul e deschis
		{
			//citirea stringului in fisierul binar:
			int lungNume = 0;
			f.read((char*)&lungNume, sizeof(lungNume));
			char* aux = new char[lungNume + 1];
			f.read(aux, lungNume + 1);
			this->nume = aux;
			delete[] aux;

			//citirea char* in fisierul binar:
			if (this->specializare != NULL)
			{
				delete[] this->specializare;
			}
			int lungSpecializare = 0;
			f.read((char*)&lungSpecializare, sizeof(lungSpecializare));
			this->specializare = new char[lungSpecializare + 1];
			f.read(this->specializare, lungSpecializare + 1);
			f.read((char*)&this->nr_ore_lucrate, sizeof(this->nr_ore_lucrate));
			f.read((char*)&this->salariu, sizeof(this->salariu));

			f.close();
		}
		else
		{
			cout << "Eroare la deschiderea fisierului!" << endl;
		}
	}


	//operatorul >>
	friend istream& operator>>(istream& i, PersonalMedical& pm)
	{
		if (pm.specializare != NULL)
		{
			delete[] pm.specializare;
		}
		cout << "Introduceti numele personalului Medical : ";
		i.ignore();
		getline(i, pm.nume);
		pm.specializare = new char[100];
		cout << "Introduceti specializarea: "; i >> pm.specializare;
		cout << "Introduceti numarul de ore lucrate: "; i >> pm.nr_ore_lucrate;
		cout << "Introduceti salariul: "; i >> pm.salariu;

		return i;
	}

	//supraincarcarea operatorului ==
	bool operator==(const PersonalMedical& pm)
	{
		if (this->nume == pm.nume)
		{
			return true;
		}

		if (this->specializare == pm.specializare)
		{
			return true;
		}

		if (this->salariu == pm.salariu)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//supraincarcarea operatorului +
	PersonalMedical operator+(const PersonalMedical& pm)
	{
		PersonalMedical copie(*this);
		copie.salariu += pm.salariu;
		return copie;

	}

	friend void bonusSalariu(const PersonalMedical& pm);
	friend void concediuMedical(const PersonalMedical& pm);
};

int PersonalMedical::numar_total_personal = 0;

void bonusSalariu(const PersonalMedical& pm)
{
	cout << "[" << pm.nume << "] a cerut un bonus la salariu." << endl;
	if (pm.tipContract == "Perioada determinata" || pm.tipContract == "perioada determinata")
	{
		if (pm.nr_ore_lucrate >= 160 && pm.nr_ore_lucrate <= 200)
		{
			cout << "Doctorul a lucrat [" << pm.nr_ore_lucrate << "] pe luna, astfel el va beneficia de un spor de 10% la salariu." << endl;
			int x = pm.salariu;
			x += pm.salariu * 0.1;
			cout << "Salariul doctorului va deveni: " << x << endl;
		}
		else if (pm.nr_ore_lucrate >= 201 && pm.nr_ore_lucrate <= 249)
		{
			cout << "Doctorul a lucrat [" << pm.nr_ore_lucrate << "] pe luna, astfel el va beneficia de un spor de 13% la salariu." << endl;
			int x = pm.salariu;
			x += pm.salariu * 0.13;
			cout << "Salariul doctorului va deveni: " << x << endl;
		}
		else if (pm.nr_ore_lucrate >= 250)
		{
			cout << "Doctorul a lucrat [" << pm.nr_ore_lucrate << "] pe luna, astfel el va beneficia de un spor de 15% la salariu." << endl;
			int x = pm.salariu;
			x += pm.salariu * 0.15;
			cout << "Salariul doctorului va deveni: " << x << endl;
		}
		else
		{
			cout << "Doctorul a lucrat prea putin pentru a beneficia de un bonus la salariu." << endl;
		}
	}
	else
	{
		cout << "Doctorul are un contract pe perioada nedeterminata, astfel nu poate beneficia de un bonus la salariu!";
	}
}

void concediuMedical(const PersonalMedical& pm)
{
	cout << "Dr. [" << pm.nume << "] a cerut concediu medical." << endl;
	int y = pm.salariu;
	y = pm.salariu * 0.8;
	cout << "Astfel, doctorul va fi platit cu 80% din salariul sau. Salariul doctorului va deveni: " << y << endl;
}

//relatia de is-a (mostenire)
class Angajat : public PersonalMedical
{
private:

	string titluPost;
	int id;
	int varsta;
	static int ultimID;
	string nivelEducatie;
	string stareCivila;

public:

	Angajat() : PersonalMedical()
	{

		this->titluPost = "Doctor";
		this->id = ++ultimID;
		this->varsta = 45;
		this->nivelEducatie = "Masterat";
		this->stareCivila = "Necasatorit/a";

	}

	Angajat(string titluPost, int varsta, string nivelEducatie, string stareCivila, string nume, float salariu, const string tipContract, const char* specializare, int nr_ore_lucrate) : PersonalMedical(nume, salariu, tipContract, specializare, nr_ore_lucrate)
	{

		this->titluPost = titluPost;
		this->id = ++ultimID;
		this->nivelEducatie = nivelEducatie;
		this->stareCivila = stareCivila;

	}

	//constructor de copiere
	Angajat(const Angajat& a) : PersonalMedical(a)
	{

		this->titluPost = a.titluPost;
		this->id = a.id;
		this->nivelEducatie = a.nivelEducatie;
		this->stareCivila = a.stareCivila;

	}

	//operator =
	Angajat& operator=(const Angajat& a)
	{
		if (this != &a)
		{
			PersonalMedical::operator+(a);
			this->titluPost = a.titluPost;
			this->id = a.id;
			this->nivelEducatie = a.nivelEducatie;
			this->stareCivila = a.stareCivila;
		}

		return *this;
	}

	//get-eri
	string getTitluPost()
	{
		return this->titluPost;
	}

	int getID()
	{
		return this->id;
	}

	string getNivelEducatie()
	{
		return this->nivelEducatie;
	}

	string getStareCivila()
	{
		return this->stareCivila;
	}

	//set-eri
	void setTitluPost(string titlu)
	{
		if (titlu.size() >= 5)
		{
			this->titluPost = titlu;
		}
		else
		{
			cerr << "Titlu post inexistent!" << endl;
		}
	}

	void setID(int id)
	{
		if (id >= 100)
		{
			this->id = id;
		}
		else
		{
			cerr << "ID-ul nu poate fi mai mic decat 100!" << endl;
		}
	}

	void setNivelEducatie(string nivelEducatie)
	{
		if (nivelEducatie == "Licentiat" || nivelEducatie == "Masterat" || nivelEducatie == "Doctorat")
		{
			this->nivelEducatie = nivelEducatie;
		}
		else
		{
			cerr << "Atentie, nu ati scris prima litera de tipar SAU nivelul de educatie spus de dv. este neexistent!" << endl;
		}
	}

	void setStareCivila(string stareCivila)
	{
		if (stareCivila == "Necasatorit/a" || stareCivila == "Casatorit/a")
		{
			this->stareCivila = stareCivila;
		}
		else
		{
			cerr << "Atentie, exista doar ~Necasatorit/a~ sau ~Casatorit/a~ !! " << endl;
		}
	}

	//destructor
	~Angajat()
	{

	}

	//operator <<
	friend ostream& operator<<(ostream& out, Angajat& a)
	{

		out << (PersonalMedical&)a;
		out << "Titlu post: " << a.titluPost << endl;
		out << "ID: " << a.id << endl;
		out << "Nivel educatie: " << a.nivelEducatie << endl;
		out << "Stare civila: " << a.stareCivila << endl;

		return out;
	}

	//supraincarcare operator > // compara doua nivele de educatie
	bool operator>(const Angajat& a)
	{
		if (this->nivelEducatie == "Masterat" && a.nivelEducatie == "Licentiat")
		{
			return true;
		}
		else if (this->nivelEducatie == "Licentiat" && a.nivelEducatie == "Masterat")
		{
			return false;
		}
		else if (this->nivelEducatie == "Doctorat" && a.nivelEducatie == "Masterat")
		{
			return true;
		}
		else if (this->nivelEducatie == "Masterat" && a.nivelEducatie == "Doctorat")
		{
			return false;
		}
		else if (this->nivelEducatie == "Doctorat" && a.nivelEducatie == "Licentiat")
		{
			return true;
		}
		else if (this->nivelEducatie == "Licentiat" && a.nivelEducatie == "Doctorat")
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

int Angajat::ultimID = 100;

int main()
{
	//prezentare proiect: fisiere text medicament, si fisiere binare personal medical

	//introducerea unui medicament intr-un fisier text.
	cout << "Testarea fisierului text: " << endl;
	ofstream medicamentFisierTextIN("medicamente.txt");
	cout << "" << endl;
	cout << "Introduceti medicament in fisierul text: " << endl;
	Medicament medicamentText;
	cin >> medicamentText;
	cout << "" << endl;

	if (medicamentFisierTextIN)
	{
		medicamentFisierTextIN << medicamentText;
		medicamentFisierTextIN.close();
		cout << "Datele medicamentului au fost scrise in fisierul text, cu succes!" << endl;
	}
	else
	{
		cout << "Eroare la deschiderea fisierului!" << endl;
	}

	//citirea medicamentului din fisierul text.
	cout << "" << endl;
	cout << "--------------------------" << endl;
	cout << "" << endl;
	ifstream medicamentFisierTextOUT("medicamente.txt");
	Medicament medicamentCitit;

	if (medicamentFisierTextOUT)
	{

		medicamentFisierTextOUT >> medicamentText;
		cout << medicamentText;
		medicamentFisierTextOUT.close();

		cout << "Medicamentul a fost citit cu succes din fisierul text!" << endl;

	}
	else
	{

		cout << "Eroare la deschiderea fisierului text!" << endl;

	}

	cout << "" << endl;
	cout << "--------------------------" << endl;
	cout << "" << endl;

	//fisierele binare acum
	cout << "Testarea fisierului binar: " << endl;
	cout << "" << endl;
	PersonalMedical personalBinar("Leonardo Marcu", 8000);
	personalBinar.scriereInBinar("personal_medical.bin");


	cout << "Citirea din fisierul binar: " << endl;
	PersonalMedical personalBinarCitit;
	personalBinarCitit.citesteInBinar("personal_medical.bin");
	cout << personalBinarCitit;

	cout << "" << endl;
	cout << "-------------------------" << endl;
	cout << "" << endl;


	//// CLASA PACIENT
	//cout << "--- --- --- PACIENTI --- --- ---" << endl;

	//Pacient pacient;
	//cout << "" << endl;
	//cout << "Testarea constructorului implicit: " << endl;
	//cout << "" << endl;

	//pacient.afisare_pacient();

	//cout << "--------------------------" << endl;

	//cout << "Testarea constructorului cu un parametru: " << endl;
	//cout << "" << endl;

	//Pacient pacient1(50);
	//pacient1.afisare_pacient();

	//cout << "--------------------------" << endl;

	//cout << "Testarea constructorului cu toti parametrii: " << endl;
	//cout << "" << endl;

	//Pacient pacient2("Marius Bica", "Camera 102", 40, "Masculin", 1, 180, 79);
	//pacient2.afisare_pacient();

	//cout << "--------------------------" << endl;

	//Pacient pacient3 = pacient2;
	//cout << "Testarea constructorului de copiere: " << endl;
	//cout << "" << endl;

	//pacient3.afisare_pacient();

	//cout << "--------------------------" << endl;

	//cout << "Testarea tuturor get-erilor, in cadrul pacientului de mai devreme: " << endl;
	//cout << "" << endl;

	//cout << pacient3.getID() << endl;
	//cout << pacient3.getNume() << endl;
	//cout << pacient3.getVarsta() << endl;
	//cout << pacient3.getGen() << endl;
	//cout << pacient3.getAnalize() << endl;
	//cout << pacient3.getInaltime() << endl;
	//cout << pacient3.getGreutate() << endl;
	//cout << "--------------------------" << endl;

	//cout << "Testarea tuturor set-erilor, in cadrul pacientului de mai devreme: " << endl;
	//cout << "" << endl;

	//pacient3.setID(100);
	//pacient3.setNume("Anamaria Popa");
	//pacient3.setVarsta(30);
	//pacient3.setGen("Feminin");
	//pacient3.setAnalize(1);
	//pacient3.setInaltime(167);
	//pacient3.setGreutate(60);
	//pacient3.afisare_pacient();


	//cout << "--------------------------" << endl;

	//cout << "Testarea operatorului = : " << endl;

	//Pacient pacient4(50);
	//Pacient pacient5;
	//pacient5 = pacient4;
	//cout << "" << endl;
	//pacient5.afisare_pacient();

	//cout << "--------------------------" << endl;


	//cout << "Testarea operatorilor >> si <<: " << endl;
	//cout << "" << endl;

	//Pacient pacient6;
	//cin >> pacient6;
	//cout << "" << endl;
	//cout << pacient6;

	//cout << "--------------------------" << endl;

	//cout << "Testarea functiilor prietene: " << endl;
	//cout << "" << endl;
	//cout << "Un pacient poate beneficia de un calcul al Indicelui Masei Corporale, doar daca si-a facut analizele!" << endl;

	//cout << "" << endl;
	//calcul_imc(pacient6);
	//cout << "" << endl;
	//reducere(pacient6);
	//cout << "--------------------------" << endl;

	//cout << "Testarea operatorilor > si <: " << endl;
	//cout << "" << endl;

	//if (pacient6 > pacient5)
	//{
	//	cout << "Varsta pacientului " << pacient6.getNume() << " este mai mare decat a pacientului " << pacient5.getNume() << "!" << endl;
	//}
	//else
	//{
	//	cout << "Varsta pacientului " << pacient6.getNume() << " este mai mica decat a pacientului " << pacient5.getNume() << "!" << endl;
	//}

	//cout << "" << endl;

	//if (pacient6 < pacient5)
	//{
	//	cout << "Greutatea pacientului " << pacient6.getNume() << " este mai mica decat a pacientului " << pacient5.getNume() << "!" << endl;
	//}
	//else
	//{
	//	cout << "Greutatea pacientului " << pacient6.getNume() << " este mai mare decat a pacientului " << pacient5.getNume() << "!" << endl;

	//}

	//cout << "--------------------------" << endl;
	//cout << "Testarea metodei statice: " << endl;

	//cout << "" << endl;
	//cout <<"Numarul total de pacienti inregistrati: "<< Pacient::afisare_numar_total_pacienti() << endl;
	//cout << "" << endl;
	//cout << "--------------------------" << endl;
	//cout << "" << endl;

	////vectorul de pacienti
	//int n;
	//cout << "Introduceti numarul de pacienti pe care vreti sa ii inregistrati in vector: "; cin >> n;
	//cout << "-------------------------" << endl;

	//vector<Pacient> pacientii(n);
	//for (int i = 0; i < n; i++)
	//{
	//	cin >> pacientii[i];
	//	cout << "-------------------------" << endl;
	//}

	////afisare vector de obiecte
	//cout << "VECTOR PACIENTI" << endl;
	//for (int i = 0; i < n; i++)
	//{
	//	cout << "Pacientul [" << i << "] : " << endl;
	//	cout << pacientii[i] << endl;
	//}

	//cout << "" << endl;
	//cout << "--------------------------" << endl;
	//cout << "" << endl;


	////testare fisiere text, introducerea unui pacient in fisierul text
	//cout << "Testarea fisiere text: " << endl;
	//cout << "" << endl;

	//ofstream scrieInFisierTextPacienti("pacienti.txt");
	//Pacient pacientText;
	//cout << "Introduceti pacientul in fisierul text: " << endl;
	//cin >> pacientText;


	//if (scrieInFisierTextPacienti)
	//{
	//	scrieInFisierTextPacienti << pacientText << endl;
	//	scrieInFisierTextPacienti.close();
	//	cout << "--------------------------" << endl;
	//	cout << "Datele pacientului au fost introduse cu succes!" << endl;
	//	cout << "--------------------------" << endl;		
	//}
	//else
	//{
	//	cout << "Eroare la deschiderea fisierului!" << endl;
	//}

	////citirea din fisierul text
	//cout << "" << endl;
	//cout << "--------------------------" << endl;
	//cout << "" << endl;

	//ifstream citesteDinFisierTextPacienti("pacienti.txt");
	//Pacient pacientCitit;

	//if (citesteDinFisierTextPacienti)
	//{
	//	cout << "Datele pacientului din fisierul text: " << endl;
	//	citesteDinFisierTextPacienti >> pacientCitit;
	//	cout << pacientCitit << endl;
	//	citesteDinFisierTextPacienti.close();
	//	cout << "Datele au fost citite cu succes!" << endl;
	//}
	//else
	//{
	//	cout << "Fisierul text nu s-a putut deschide." << endl;
	//}


	//// CLASA 2 - MEDICAMENT
	//
	//cout << "--- --- --- MEDICAMENTE --- --- ---" << endl;
	//cout << "" << endl;

	//cout << "Testarea constructorului implicit: " << endl;
	//cout << "" << endl;
	//Medicament medicament1;
	//medicament1.afisare_medicament();
	//cout << "--------------------------" << endl;

	//cout << "Testarea constructorului cu un parametru : " << endl;
	//cout << "" << endl;
	//Medicament medicament2(15.45);
	//medicament2.afisare_medicament();
	//cout << "--------------------------" << endl;

	//cout << "Testarea constructorului cu toti parametrii: " << endl;
	//cout << "" << endl;
	//Medicament medicament3("Abatixent", 27.15, 2, "Anticoagulant", 1);
	//medicament3.afisare_medicament();
	//cout << "--------------------------" << endl;

	//cout << "Testarea constructorului de copiere: " << endl;
	//cout << "" << endl;
	//Medicament medicament4 = medicament3;
	//medicament4.afisare_medicament();
	//cout << "--------------------------" << endl;

	//cout << "Testarea get-erilor si set-erilor medicamentului de mai devreme: " << endl;
	//cout << medicament4.getCod() << endl;
	//cout << medicament4.getNume() << endl;
	//cout << medicament4.getPret() << endl;
	//cout << medicament4.getCantitate() << endl;
	//cout << medicament4.getStoc() << endl;
	//cout << "" << endl;
	//cout << "--------------------------" << endl;
	//medicament4.setNume("Aflen");
	//medicament4.setCod(99);
	//medicament4.setPret(14.55);
	//medicament4.setStoc(1);
	//medicament4.setCantitate(2);
	//medicament4.afisare_medicament();
	//cout << "" << endl;
	//cout << "--------------------------" << endl;

	//cout << "Testarea operatorului = : " << endl;
	//cout << "" << endl;
	//Medicament medicament5;
	//medicament5 = medicament4;
	//medicament5.afisare_medicament();
	//cout << "--------------------------" << endl;

	//cout << "Testarea operatorilor >> si <<: " << endl;
	//cout << "" << endl;

	//Medicament medicament6;
	//cin >> medicament6;
	//cout << "" << endl;
	//cout << medicament6;

	//cout << "--------------------------" << endl;

	//cout << "Testarea functiilor prietene: " << endl;
	//cout << "" << endl;

	//valoare_medicament(medicament6);
	//efecte_secundare(medicament6);
	//cout << "" << endl;
	//cout << "--------------------------" << endl;

	//cout << "Testarea operatorilor ++, -- pre si post" << endl;
	//cout << "" << endl;
	//++medicament6; //s-a produs cresterea cantitatii cerute a medicamentului cu 5 unitati
	//cout << medicament6;
	//--medicament6; //s-a produs scaderea cantitatii cerute a medicamentului cu o unitate
	//cout << "" << endl;
	//cout << medicament6;

	//cout << "--------------------------" << endl;
	//cout << "" << endl;
	//Medicament medicament7;
	//medicament7 = medicament6++; // cantitatea din medicamentul 7 ia valoarea initiala a lui 6, iar din 6 se incrementeaza cu valoarea 5.
	//cout << medicament7;
	//cout << "" << endl;
	//cout << "--------------------------" << endl;
	//cout << medicament6;
	//cout << "" << endl;
	//cout << "--------------------------" << endl;
	//medicament7 = medicament6--; // cantitatea din medicamentul 7 ia valoarea din medicamentul 6, iar medicamentul 6 scade cu o unitate.
	//cout << medicament7;
	//cout << "" << endl;
	//cout << "--------------------------" << endl;
	//cout << medicament6;
	//cout << "" << endl;
	//cout << "--------------------------" << endl;

	//cout << "Testarea metodei statice: " << endl;

	//cout << "" << endl;
	//cout <<"Suma totala a preturilor medicamentelor inregistrate este: "<< Medicament::returnare_suma_totala() << endl;
	//cout << "" << endl;
	//cout << "--------------------------" << endl;
	//cout << "" << endl;

	////vectorul de medicamente
	//cout << "VECTOR MEDICAMENTE" << endl;
	//int m;
	//cout << "Introduceti numarul de medicamente pe care vreti sa ii inregistrati in vector: "; cin >> m;
	//cout << "-------------------------" << endl;

	//vector<Medicament> medicamente(m);
	//for (int i = 0; i < m; i++)
	//{

	//	cin >> medicamente[i];
	//	cout << "--------------------------" << endl;

	//}

	////afisare vector de medicamente
	//for (int i = 0; i < m; i++)
	//{
	//	cout << "Medicamentul [" << i << "] : " << endl;
	//	cout << medicamente[i];
	//	cout << "" << endl;
	//}
	//
	//cout << "" << endl;
	//cout << "--------------------------" << endl;
	//cout << "" << endl;

	////introducerea unui medicament intr-un fisier text.
	//cout << "Testarea fisierului text: " << endl;
	//ofstream medicamentFisierTextIN("medicamente.txt");
	//cout << "" << endl;
	//cout << "Introduceti medicament in fisierul text: " << endl;
	//Medicament medicamentText;
	//cin >> medicamentText;
	//cout << "" << endl;

	//if (medicamentFisierTextIN)
	//{
	//	medicamentFisierTextIN << medicamentText;
	//	medicamentFisierTextIN.close();
	//	cout << "Datele medicamentului au fost scrise in fisierul text, cu succes!" << endl;
	//}
	//else
	//{
	//	cout << "Eroare la deschiderea fisierului!" << endl;
	//}

	////citirea medicamentului din fisierul text.
	//cout << "" << endl;
	//cout << "--------------------------" << endl;
	//cout << "" << endl;
	//ifstream medicamentFisierTextOUT("medicamente.txt");
	//Medicament medicamentCitit;
	//
	//if (medicamentFisierTextOUT)
	//{

	//	medicamentFisierTextOUT >> medicamentText;
	//	cout << medicamentText;
	//	medicamentFisierTextOUT.close();

	//	cout << "Medicamentul a fost citit cu succes din fisierul text!" << endl;

	//}
	//else
	//{

	//	cout << "Eroare la deschiderea fisierului text!" << endl;

	//}

	//cout << "" << endl;
	//cout << "--------------------------" << endl;
	//cout << "" << endl;

	//// CLASA 3 - PERSONAL MEDICAL

	//cout << "--- --- --- PERSONAL MEDICAL --- --- ---" << endl;

	//cout << "" << endl;
	//cout << "Testarea constructorului implicit: " << endl;
	//cout << "" << endl;

	//PersonalMedical personal1;
	//personal1.afisare_personal_medical();

	//cout << "" << endl;
	//cout << "--------------------------" << endl;
	//cout << "Testarea constructorului cu doi parametri: " << endl;
	//cout << "" << endl;

	//PersonalMedical personal2("Necula Bogdan", 8700);
	//personal2.afisare_personal_medical();
	//
	//cout << "" << endl;
	//cout << "--------------------------" << endl;
	//cout << "Testarea constructorului cu toti parametrii: " << endl;
	//cout << "" << endl;

	//PersonalMedical personal3("Alina Manea", 7000, "Perioada determinata", "Patologie", 115);
	//personal3.afisare_personal_medical();

	//cout << "" << endl;
	//cout << "--------------------------" << endl;
	//cout << "Testarea constructorului de copiere: " << endl;
	//cout << "" << endl;

	//PersonalMedical personal4 = personal3;
	//personal4.afisare_personal_medical();

	//cout << "" << endl;
	//cout << "--------------------------" << endl;
	//cout << "Testarea get-erilor si set-erilor cadrului de mai devreme: " << endl;
	//cout << "" << endl;

	//cout << personal4.getNume() << endl;
	//cout << personal4.getSalariu() << endl;
	//cout << personal4.getContract() << endl;
	//cout << personal4.getSpecializare() << endl;
	//cout << personal4.getNrOre() << endl;

	//cout << "" << endl;
	//cout << "--------------------------" << endl;
	//cout << "" << endl;

	//personal4.setNume("Maria Oprea");
	//personal4.setSalariu(6000);
	//personal4.setSpecializare("Dermatologie");
	//personal4.setNrOre(111);
	//personal4.afisare_personal_medical();

	//cout << "" << endl;
	//cout << "--------------------------" << endl;

	//cout << "Testarea operatorului = : " << endl;
	//cout << "" << endl;

	//PersonalMedical personal5;
	//personal5 = personal4;

	//personal5.afisare_personal_medical();

	//cout << "" << endl;
	//cout << "--------------------------" << endl;
	//cout << "" << endl;

	//cout << "Testarea operatorilor >> si <<: " << endl;
	//cout << "" << endl;

	//PersonalMedical personal6;
	//cin >> personal6;
	//cout << "" << endl;
	//cout << personal6;
	//cout << "" << endl;

	//cout << "--------------------------" << endl;
	//cout << "" << endl;

	//cout << "Testarea functiilor prietene: " << endl;
	//cout << "" << endl;

	//bonusSalariu(personal6);
	//concediuMedical(personal6);

	//cout << "" << endl;
	//cout << "--------------------------" << endl;
	//cout << "" << endl;

	//cout << "Testarea operatorului== "<< endl;
	//cout << "" << endl;

	//if (personal5 == personal4)
	//{
	//	cout << "Obiectele sunt identice" << endl;
	//}
	//else
	//{
	//	cout << "Obiectele sunt diferite" << endl;
	//}

	//cout << "" << endl;

	//if (personal5 == personal1)
	//{
	//	cout << "Obiectele sunt diferite" << endl;
	//}
	//else
	//{
	//	cout << "Obiectele sunt identice" << endl;
	//}

	//cout << "" << endl;
	//cout << "Testarea operatorului +: " << endl;

	//PersonalMedical personalTest = personal6 + personal4; // salariul obiectului personal6 va fi adunat cu valoarea salariului personal4.
	//cout << personalTest;

	//cout << "" << endl;
	//cout << "-------------------------" << endl;

	////vectorul de personal medical
	//cout << "VECTOR PERSONAL MEDICAL" << endl;
	//cout << "" << endl;
	//int r;
	//cout << "Introduceti numarul de cadre medicale pe care vreti sa le inregistrati in vector: "; cin >> r;
	//cout << "-------------------------" << endl;

	//vector<PersonalMedical> cadre(r);
	//for (int i = 0; i < r; i++)
	//{

	//	cin >> cadre[i];
	//	cout << "--------------------------" << endl;

	//}

	////afisare vector de personal medical
	//for (int i = 0; i < r; i++)
	//{
	//	cout << "Cadrul medical [" << i << "] : " << endl;
	//	cout << cadre[i];
	//	cout << "" << endl;
	//}
	//
	//cout << "" << endl;
	//cout << "--------------------------" << endl;
	//cout << "" << endl;


	////matrice de obiecte
	//cout << "MATRICE DE PERSONAL MEDICAL: " << endl;
	//cout << "" << endl;
	//int nrLinii, nrColoane;
	//cout << "-------------------------" << endl;
	//cout << "Introduceti numarul de linii: "; cin >> nrLinii;
	//cout << "Introduceti numarul de coloane: "; cin >> nrColoane;
	//cout << "-------------------------" << endl;
	//cout << "" << endl;

	//vector<vector<PersonalMedical>> cadreMedicale(nrLinii, vector<PersonalMedical>(nrColoane));

	////introducere date in matrice
	//cout << "Introduceti cadrele medicale in matrice: " << endl;
	//cout << "" << endl;
	//for (int i = 0; i < nrLinii; i++)
	//{
	//	for (int j = 0; j < nrColoane; j++)
	//	{
	//		cout << "-------------------------" << endl;
	//		cout << "Introduceti datele pentru cadrul medical [" << i << "]" << "[" << j << "]: " << endl;
	//		cin >> cadreMedicale[i][j];
	//	}
	//}

	////afisare date din matrice
	//for (int i = 0; i < nrLinii; i++)
	//{
	//	for (int j = 0; j < nrColoane; j++)
	//	{
	//		cout << "Cadrul medical [" << i << "]" << "[" << j << "]: \n";
	//		cadreMedicale[i][j].afisare_personal_medical();
	//		cout << "-------------\n";
	//	}
	//}

	//cout << "" << endl;
	//cout << "-------------------------" << endl;
	//cout << "" << endl;

	////testare fisier binar
	//cout << "Testarea fisierului binar: " << endl;
	//cout << "" << endl;
	//PersonalMedical personalBinar("Leonardo Marcu", 8000);
	//personalBinar.scriereInBinar("personal_medical.bin");


	//cout << "Citirea din fisierul binar: " << endl;
	//PersonalMedical personalBinarCitit;
	//personalBinarCitit.citesteInBinar("personal_medical.bin");
	//cout << personalBinarCitit;

	//cout << "" << endl;
	//cout << "-------------------------" << endl;
	//cout << "" << endl;

	//// CLASA 4 - FARMACIE
	//cout << "--------- FARMACIE ----------" << endl;
	//cout << "" << endl;
	//Medicament medicamentFarmacie("Parasinus Forte", 12.25, 2, "Analgezic", 1);

	//cout << "Testarea constructorului implicit: " << endl;
	//cout << "" << endl;
	//Farmacie farmacie1;
	//cout << farmacie1;
	//cout << "" << endl;

	//cout << "Testarea constructorului cu un parametru: " << endl;
	//cout << "" << endl;
	//Farmacie farmacie2("HelpNet", medicamentFarmacie);
	//cout << farmacie2;
	//cout << "" << endl;

	//cout << "Testarea constructorului cu toti parametrii: " << endl;
	//cout << "" << endl;
	//Farmacie farmacie3("Tei", "0245-100-100", "Strada Luca", 0, medicamentFarmacie);
	//cout << farmacie3;
	//cout << "" << endl;

	//cout << "-------------------------" << endl;
	//cout << "" << endl;

	//cout << "Testarea functiei daca medicamentul se afla in farmacie: " << endl;
	//cout << "" << endl;
	//Medicament medicament100("Nurofen Forte", 25.45, 2, "Analgezic", 1);
	//farmacie3.afisareMedicamentDinFarmacie();

	//cout << "" << endl;
	//cout << "-------------------------" << endl;

	//cout << "Testarea operatorului >>" << endl;
	//cout << "" << endl;
	//Farmacie farmacie4;
	//cin >> farmacie4;
	//cout << "" << endl;
	//cout << farmacie4;

	//cout << "" << endl;
	//cout << "-------------------------" << endl;
	//cout << "" << endl;


	//cout << "Testarea operatorului != " << endl;
	//cout << "" << endl;
	//if (farmacie1 != farmacie2)
	//{
	//	cout << "Farmacia [" << farmacie1.getNumeFarmacie() << "] beneficiaza de consultare a tensiunii arteriale, iar farmacia [" << farmacie2.getNumeFarmacie() << "] nu beneficiaza." << endl;
	//}
	//else if (farmacie2 != farmacie1)
	//{
	//	cout << "Farmacia [" << farmacie2.getNumeFarmacie() << "] beneficiaza de consultare a tensiunii arteriale, iar farmacia [" << farmacie1.getNumeFarmacie() << "] nu beneficiaza." << endl;
	//}
	//else
	//{
	//	cout << "Ambele farmacii dispun de consultare gratis a tensiunii arteriale!";
	//}

	//cout << "" << endl;
	//cout << "-------------------------" << endl;
	//cout << endl;

	////testare fisiere binare
	//cout << "Testare fisier binar: " << endl;
	//cout << "" << endl;
	//Farmacie farmacieBinar("Catena", "0100-100-100", "Bulevardul Iuliu Maniu", 1, medicamentFarmacie);
	//farmacieBinar.scrieInBinar("farmacie.bin");

	//cout << "" << endl;
	//cout << "Citirea din binar: " << endl;
	//Farmacie farmacieCitit;
	//farmacieCitit.citesteDinBinar("farmacie.bin");
	//cout << farmacieCitit;

	//cout << "" << endl;
	//cout << "-------------------------" << endl;
	//cout << "" << endl;


	//// CLASA 5 - DETALII SANATATE
	//cout << "--- --- --- DETALII SANATATE --- --- ---" << endl;
	//cout << "" << endl;

	//cout << "Testare constructor implicit: " << endl;

	//cout << "" << endl;
	//DetaliiSanatate detalii1;
	//cout << detalii1 << endl;
	//cout << "" << endl;

	//cout << "Testare constructor cu toti parametrii: " << endl;
	//
	//cout << "" << endl;
	//int nrConsultatii = 3;
	//int* frecventaCardiaca = new int[nrConsultatii] {80, 85, 90};
	//DetaliiSanatate detalii2(nrConsultatii, frecventaCardiaca, 77, 115, 65, "Ionut Mihaescu", "Camera 105", 35, "Masculin", 1, 177, 76);
	//cout << detalii2 << endl;
	//cout << "" << endl;

	//cout << "" << endl;
	//cout << "-------------------------" << endl;
	//cout << "" << endl;

	//cout << "Testarea constructorului de copiere: " << endl;
	//cout << "" << endl;
	//DetaliiSanatate detalii3 = detalii2;
	//cout << detalii3 << endl;
	//cout << "" << endl;

	//cout << "" << endl;
	//cout << "-------------------------" << endl;
	//cout << "" << endl;

	//cout << "Testarea get-erilor si set-erilor pentru obiectul de mai devreme: " << endl;
	//cout << "" << endl;

	//cout << detalii3.getNrConsultatii() << endl;
	//int* frecventa = detalii3.getFrecventa();
	//for (int i = 0; i < detalii3.getNrConsultatii()-1; i++)
	//{
	//	cout << frecventa[i] << ", ";
	//}
	//cout << frecventa[detalii3.getNrConsultatii() - 1] << endl;
	//cout << detalii3.getNivelZahar() << endl;
	//cout << detalii3.getSistolica() << endl;
	//cout << detalii3.getDiastolica() << endl;

	//cout << "-----------------------" << endl;

	//int nrConsultatii1 = 5;
	//int* frecventa1 = new int[nrConsultatii1] { 75, 76, 80, 87, 90};
	//detalii3.setNrConsultatii(nrConsultatii1);
	//detalii3.setFrecventa(nrConsultatii1, frecventa1);
	//detalii3.setNivelZahar(80);
	//detalii3.setSistolica(115);
	//detalii3.setDiastolica(85);
	//cout << detalii3 << endl;

	//cout << "-------------------------" << endl;
	//cout << "" << endl;

	//cout << "Testarea operatorului =: " << endl;
	//cout << "" << endl;

	//DetaliiSanatate detalii4;
	//detalii4 = detalii3;
	//cout << detalii4;

	//cout << "" << endl;
	//cout << "-------------------------" << endl;
	//cout << "" << endl;

	//cout << "Testarea metodei de calculare a frecventei medie, cat si functia prietena: " << endl;

	//detalii4.calculareFrecventaMedie();
	//cout << "" << endl;
	//detaliiNivelZahar(detalii4);

	//cout << "" << endl;
	//cout << "-------------------------" << endl;
	//cout << "" << endl;

	//cout << "Realizare upcasting:" << endl;
	//cout << "" << endl;

	//Pacient* pacientCasting = &detalii4;

	//pacientCasting->setNume("Izabela Moraru");
	//pacientCasting->setVarsta(24);
	//pacientCasting->setGen("Feminin");
	//pacientCasting->afisare_pacient();

	//cout << "" << endl;
	//cout << "-------------------------" << endl;
	//cout << "" << endl;

	//// CLASA 6 - ANGAJAT -> mostenita din PERSONAL MEDICAL
	//cout << "--- --- --- ANGAJAT --- --- ---" << endl;
	//cout << "" << endl;

	//cout << "Testare constructor implicit: " << endl;

	//cout << "" << endl;
	//Angajat angajat1;
	//cout << angajat1;
	//cout << "" << endl;

	//cout << "Testare constructor cu toti parametrii: " << endl;

	//cout << "" << endl;
	//Angajat angajat2("Asistent", 31, "Masterat", "Necasatorit/a", "Andreea Popa", 4000, "Nedeterminata", "Oftalmologie", 65);
	//cout << angajat2;
	//cout << "" << endl;

	//cout << "Testare constructor de copiere: " << endl;
	//
	//cout << "" << endl;
	//Angajat angajat3 = angajat2;
	//cout << angajat3;
	//cout << "" << endl;

	//cout << "" << endl;
	//cout << "-------------------------" << endl;
	//cout << "" << endl;

	//cout << "Testare operator =: " << endl;
	//
	//cout << "" << endl;
	//Angajat angajat4;
	//angajat4 = angajat1;
	//cout << angajat4;
	//

	//cout << "" << endl;
	//cout << "-------------------------" << endl;
	//cout << "" << endl;

	//cout << "Testare get-eri si set-eri: " << endl;
	//cout << "" << endl;

	//cout << angajat4.getTitluPost() << endl;
	//cout << angajat4.getID() << endl;
	//cout << angajat4.getNivelEducatie() << endl;
	//cout << angajat4.getStareCivila() << endl;

	//cout << "" << endl;
	//cout << "-------------------------" << endl;

	//angajat4.setTitluPost("Doctor");
	//angajat4.setID(115);
	//angajat4.setNivelEducatie("Licentiat");
	//angajat4.setStareCivila("Necasatorit/a");

	//cout << angajat4;

	//cout << "" << endl;
	//cout << "-------------------------" << endl;
	//cout << "" << endl;

	//cout << "Testarea operatorului >: " << endl; //compararea a doua nivele de educatie!

	//if (angajat2 > angajat4)
	//{
	//	cout << "Angajatul [" << angajat2.getNume() << "] are un nivel de educatie mai ridicat decat angajatul [" << angajat4.getNume() << "].";
	//}
	//else
	//{
	//	cout << "Angajatul [" << angajat4.getNume() << "] are un nivel de educatie mai ridicat decat angajatul [" << angajat2.getNume() << "].";
	//}

	//cout << "" << endl;
	//cout << "-------------------------" << endl;
	//cout << "" << endl;

	//cout << "Realizarea de upcasting: " << endl;
	//cout << "" << endl;

	//PersonalMedical* personalCasting = &angajat2;

	//personalCasting->setNrOre(100);
	//personalCasting->setNume("Floriana Iancu");
	//personalCasting->setSalariu(4555);
	//personalCasting->setSpecializare("Dermatologie");
	//personalCasting->afisare_personal_medical();

	//cout << "" << endl;
	//cout << "-------------------------" << endl;
	//cout << "" << endl;





}
