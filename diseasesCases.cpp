#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_CASES = 100;
string DiseaseID[MAX_CASES]={};
string DiseaseName[MAX_CASES]={};
string caseID[MAX_CASES]={};
string Locations[MAX_CASES]={};

//function to add location
void addLocation(string location)
{
	int i;
	for(i=0;i<MAX_CASES;i++)
	{
		if(Locations[i]=="\0")
		{
			Locations[i]=location;
			cout<<"Location "<<Locations[i]<<" is successfully added!"<<endl;
			break;
		}
	}
}

//function to delete location
void deleteLocation(string location)
{
	int i;
	for(i=0;i<MAX_CASES;i++)
	{
		if(Locations[i]==location)
		{
			Locations[i]="\0";
			DiseaseID[i]="\0";
			DiseaseName[i]="\0";
			caseID[i]="\0";
			cout<<"Location deleted successfully!!"<<endl;
			break;
		}
	}
	cout<<"the location no longer exists"<<endl;
}

//function to record dieases
void recordDisease(string diseaseID,string diseaseName)
{
	int i;
	for(i=0;i<MAX_CASES;i++)
	{
		if(DiseaseID[i]=="\0")
		{
			DiseaseID[i]=diseaseID;
			DiseaseName[i]=diseaseName;
			cout<<"Disease added successfully!!"<<endl;
			break;
		}
	}
}

//function to list location following alhabetical order
void listLocation()
{
	int i;
	for(i=0;i<MAX_CASES;i++)
	{
	
		if(Locations[i]!="\0")
		{
        //arrange locations in alphabetical order

			int j;
			for(j=i+1;j<MAX_CASES;j++)
			{
				if(Locations[j]!="\0")
				{
					if(Locations[i]>Locations[j])
					{
						string temp=Locations[i];
						Locations[i]=Locations[j];
						Locations[j]=temp;
					}
				}
			}
			
			cout<<Locations[i]<<endl;

		}
}
}

// void totalCases()
// {
// 	int i;
// 	int total=0;
// 	for(i=0;i<MAX_CASES;i++)
// 	{
// 		if(Locations[i]!="\0")
// 		{
// 			total++;
// 		}
// 	}
// 	cout<<"Total number of cases: "<<total<<endl;
// }



void listDiseases()
{
	int i;
	for(i=0;i<MAX_CASES;i++)
	{
		if(DiseaseID[i]!="\0")
		{
			//arrange diseases in alphabetical order
			int j;
			for(j=i+1;j<MAX_CASES;j++)
			{
				if(DiseaseID[j]!="\0")
				{
					if(DiseaseID[i]>DiseaseID[j])
					{
						string temp=DiseaseID[i];
						DiseaseID[i]=DiseaseID[j];
						DiseaseID[j]=temp;
						string temp1=DiseaseName[i];
						DiseaseName[i]=DiseaseName[j];
						DiseaseName[j]=temp1;
					}
				}
			}
			cout<<DiseaseID[i]<<" "<<DiseaseName[i]<<endl;
		}
	}
}

//function to find where diseases exist
void findDisease(string diseaseID)
{
	int i;
	for(i=0;i<MAX_CASES;i++)
	{
		if(DiseaseID[i]==diseaseID)
		{
			cout<<Locations[i]<<endl;
			break;
		}
	}
	if(i==MAX_CASES)
	{
		cout<<"No location with this disease"<<endl;
	}
}

//function to find total cases in a location
void totalCases(string location)
{
	int i;
	int total=0;
	for(i=0;i<MAX_CASES;i++)
	{
		if(Locations[i]==location)
		{
			total++;
		}
	}
	cout<<"Total Cases of "<<DiseaseName[i]<<" at "<<location<<" are: "<<total<<endl;
}

void totalDiseases(string diseaseName)
{
	int i;
	int total=0;
	for(i=0;i<MAX_CASES;i++)
	{
		if(DiseaseName[i]==diseaseName)
		{
			total++;
		}
	}
	cout<<"Total Cases of "<<diseaseName<<" = "<<total<<endl;
}



void helpFun(){

	        cout<<"=========================================================="<<endl;
			cout<<"*           HELP MENU                                     "<<endl;
			cout<<"=========================================================="<<endl;
			cout<<"  add <Location>                                         "<<endl;
			cout<<"  delete <Location>                                      "<<endl;
			cout<<"  Record <Location><disease><cases>                      "<<endl;
			cout<<"  list Locations                                         "<<endl;
			cout<<"  listdiseases                                          "<<endl;
			cout<<"  where disease                                          "<<endl;
			cout<<"  cases <location><disease>                              "<<endl;
			cout<<"  lases <disease>                                        "<<endl;
			cout<<"  help                                                   "<<endl;
			cout<<"  Exit                                                   "<<endl;
		
}



//a function to save to file by appending to the end of the file
void saveFile()
{
	ofstream file;
	file.open("data.txt",ios::app);
	int i;
	for(i=0;i<MAX_CASES;i++)
	{
		if(Locations[i]!="\0")
		{
			file<<Locations[i]<<","<<DiseaseID[i]<<","<<DiseaseName[i]<<","<<caseID[i]<<endl;
		}
	}
	file.close();
}

//Function to locations, diseases and cases from the file and store in the arrays
void loadFile()
{
	ifstream file;
	file.open("data.txt");
	string line;
	int i;
	for(i=0;i<MAX_CASES;i++)
	{
		getline(file,line,',');
		Locations[i]=line;
		getline(file,line,',');
		DiseaseID[i]=line;
		getline(file,line,',');
		DiseaseName[i]=line;
		getline(file,line,'\n');
		caseID[i]=line;
	}
	file.close();
}

//a function to compare two strings without case sensitivity
bool compare(string a,string b)
{
	int i;
	for(i=0;i<a.length();i++)
	{
		if(tolower(a[i])!=tolower(b[i]))
		{
			return false;
		}
	}
	return true;
}


int main(){
	
		
	string command;
	cout<<"==============================================="<<endl;
	cout<<" *  Welcome to Disease Cases Reporting System!  *" <<endl;
	cout<<" ***********************************************"<<endl;
	cout<<" *                                  *"<<endl; 
	cout<<" *  It is developed by Mugisha Edine Noella as practical *"<<endl;
	cout<<" *  evaluation for the end of Year 3."<<endl;
	cout<<"=========================================================="<<endl;
	cout<<"Starting Time: Thu Apri 05 23:59:08 CAT 2022"<<endl;
	cout<<"Need a help? Type 'help' to then press Enter key."<<endl;
 
	loadFile();
    do{
	 cin>>command;

    if(compare(command,"add"))
	{

		string location;
		cout<<"Enter the location: ";
		cin>>location;
          addLocation(location);

	} else if(compare(command,"delete")){
	
		string location;
		cout<<"Enter the location: ";
		cin>>location;
          deleteLocation(location);

	}else if(compare(command,"record") ){

		string diseaseID,diseaseName;
		cout<<"Enter the disease ID: ";
		cin>>diseaseID;
		cout<<"Enter the disease name: ";
		cin>>diseaseName;
		recordDisease(diseaseID,diseaseName);
   
	}else if(compare(command,"list locations") ){

		cout<<"List of locations: "<<endl;
        listLocation();
	

    }else if(compare(command,"listdiseases") ){

	     listDiseases();
	}else if(command == "where" ){
  
		string diseaseID;
		cout<<"Enter the disease ID: ";
		cin>>diseaseID;
        findDisease(diseaseID);

	}else if(compare(command,"cases") ){
		  string location;
		  cout<<"Enter the location: ";
		  cin>>location;
          totalCases(location);

	}else if(compare(command,"lases") ){
	
		string diseaseName;
		cout<<"Enter the disease name: ";
		cin>>diseaseName;
		
	
		totalDiseases(diseaseName);
	 
	}else if(compare(command,"help") ){
		   system("CLS");
	       helpFun();
	}else if(compare(command,"exit") ){
		  saveFile();
		  cout<<"Exiting ...";
          return 0;

	}else{
		cout<<"not a command"<<endl;
	}

	}while(command != "Exit");




	return 0;
}
