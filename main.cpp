// Kellie Henderson, Dr_T, Unit 7 assignment

#include <iostream>
#include<string>
#include<sstream> //for overriding toString() 

using namespace std; 

//Declare the structs of Unit 7
struct timeOfDay
{
  short Hour;
  short Minute; 
  short Second;
}; 

struct appDate
{
  short dayOfMonth; 
  short month; 
  int year; 
};

struct event 
{
  string eventName; 
  timeOfDay eventTime; 
  appDate eventDate; 
  bool isUrgent; 

  //make a toString() member function for event
  //giving event instructions for how to print itself
  string toString() 
  {
    short dayOfMonth = eventDate.dayOfMonth;
    short month = eventDate.month;
    int year = eventDate.year; 
    
    stringstream ss; //a custom style cout 
    ss << month << "/" << dayOfMonth << "/" << year;

    string date = ss.str(); 

    // build the time string

    short hour = eventTime.Hour;
    short minute  = eventTime.Minute;
    short second = eventTime.Second;

    stringstream sst;
    sst << hour << ":" << minute << ":" << second;

    string time = sst.str();



    return ("Date = " + date + "\nTime =  " + time);   
  }
};
void createEvent(timeOfDay &t, appDate &d, event &e);

int main() 
{ 
  /********* PART ONE **************/
 // date m/d/y time: h:m:s
 timeOfDay t; //instance of the timeOfDay struct
 t.Hour = 8;
 t.Minute = 30;
 t.Second = 22; 
 cout << "\nTime:" << endl;
 cout << t.Hour << ":" << t.Minute << ":" << t.Second << endl; 

 appDate d; 
 d.dayOfMonth = 16;
 d.month = 1;
 d.year = 1988; 
 cout << "\nDate: " << endl; 
 cout << d.month << "/" << d.dayOfMonth << "/" << d.year << endl;

 event e; 
 e.eventName = "My Date of Birth";
 int decision = 0; 
 string status = ""; 
 //determine if the event is urgent
 cout << "\n Is the event, " << e.eventName << ", urgent (1 = yes, 2 = no): ";
 cin >> decision; //ask for the input decision 
 if(decision == 1) 
 {
   e.isUrgent = true; //yes an urgent event
   status = "URGENT!"; 
 }
 else if(decision == 2)
  {
   e.isUrgent = false; //not an urgent evetn 
   status = "not urgent"; 
  }
 else
 {
   status = "error"; 
 }
 cout << "\nEvent Name: " << e.eventName << ", Status: " << status << endl; 

 //Populate the event e with a date and a time 
 e.eventDate = d; //put data into e.eventDate using an existing d instance
 e.eventTime = t; //put data into e.eventTime using an existing t instance

 //Print (reprint) the date and time of the event
 //reprint the e date
 cout << "\nEvent date: " << endl; 
 cout <<e.eventDate.month << "/" 
      << e.eventDate.dayOfMonth << "/" 
      << e.eventDate.year 
      << endl;

//reprint the e time

cout << "\nEvent time: " << endl; 
cout << e.eventTime.Hour << ":" 
     << e.eventTime.Minute << ":"
     << e.eventTime.Second << endl; 

     //inspired by the excellent mind for Rafael How do I cout << e? 
     cout << e.toString(); 
/********************** PART TWO ***********************/

   cout << "\nUnit 7, Part 2: Pass Event Objects by Reference &" << endl; 
    //declare instances of the STRUCT that we need for this work
    event eMain;
    timeOfDay tMain; //create a timeOfDay to share with eMain
    appDate dMain; //create a appDate to share with eMain
    //call a function here called void createEvent(timeOfDay t, appDate d, event e);
    /*
       pass tMain, dMain, and eMain by reference
       ask for user input to populate tMain, dMain, with data
       store these data in eMain
       ask for and store the event name and urgency
       print all the event details to screen. 
    */
   // createEvent(tMain, dMain, eMain); //function call 
createEvent(tMain, dMain, eMain);


  return 0; 
}
void createEvent(timeOfDay &t, appDate &d, event &e)
{
  short h = 0, m = 0, s = 0, mo = 0, day = 0;
  int y = 0, decision = 0; string status = "";
  string urgent = "", eName = ""; 
  cout << "\nWelcome to our custom Event Creator " <<endl; 
  getline(cin,eName); //accept spaces for input 
  //populate time of day t
  cout << "\nPlease enter an the hour, minute, and second: ";
  cin >> h >> m >> s; 
  t = {h, m, s}; 
  cout << "\n The time you entered is: " << h << ":" << m << ":"<< s << "." << endl;

  //populate appDate d
cout << "\nPlease enter the Day, month and year of the event." << endl;
cin >> day >> mo >> y ;
d = {day, mo, y};
cout << "\n The event date is: " << day << "/" << mo << "/" << y << "." << endl;

  //Set event details 
  //Populate the event name
  cout << "\n Please enter the event name: " << endl;
  cin >> eName;


  //Populate the event urgency 
   cout << "\n Is the event, " << e.eventName << ", urgent (1 = yes, 2 = no): ";
  cin >> decision; //ask for the input decision 
  status  = (decision == 1) ? "Urgent!" : "Not Urgent" ;

  cout << "\nThe event you are attending is: " << eName << "." << endl;
  cout << "\nEVENT DETAILS --- " << endl; 
  cout << "Event Name: " << eName << endl; 
  cout << "\nStatus: " << status << endl; 

  e.eventDate = d;

  e.eventTime = t;
  
  cout << e.toString(); 

}