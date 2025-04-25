#include<iostream>
using namespace std;

//define - DIP suggests that classes should rely on abstractions (e.g., interfaces or abstract classes) rather than concrete implementations.
// it states that high level modules should not depend on low level modules , both hsould depend on abstractions and abstraction should not depend on implementtion
//implementation should depend on abstractions. 

class Interfacemsg{
    public:
          virtual void send(const string& receiver , const string& msg) = 0 ;
};

class Email : public Interfacemsg{
    public:
           void send (const string& receiver , const string& msg) override {
              cout<<"Message sent to " << receiver << " and the msg is " << msg <<endl;
           }
};

class Sms : public Interfacemsg{
    public:
    void send (const string& receiver , const string& msg) override {
        cout<<"Message sent to " << receiver << " and the msg is " << msg <<endl;
       }
};

// High level module 
class Notification{
    private:
          Interfacemsg& sender;
    public:
    Notification(Interfacemsg& sender) : sender(sender) {}
    
    void sendNotification(const string& receiver, const string& message) {
        sender.send(receiver, message);
    }      
};

int main(){
    Email emailSender;
    Sms smsSender;
    
    // Inject dependencies (could be done via DI framework in real application)
    Notification emailNotification(emailSender);
    Notification smsNotification(smsSender);
    
    // Use the services
    emailNotification.sendNotification("user@example.com", "Hello via Email!");
    smsNotification.sendNotification("+123456789", "Hello via SMS!");
    
    return 0;
}