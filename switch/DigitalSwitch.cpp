#include <iostream>
#include <map>
using namespace std;

enum SwitchState {
    OFF,
    LOW,
    MODERATE,
    HIGH
};

class IContext{
    public:
    virtual void setState(SwitchState nextState) = 0;
};

class IStateHandler{
    public:
    virtual void handleState(IContext* context) = 0;
};

class IStateHandlerFactory{
    public:
    virtual IStateHandler* create(SwitchState state) = 0;
};

class OffStateHandler : public IStateHandler {
    public:
    void handleOffState(){
        std::cout<<"Handling OFF state"<<std::endl;
    }
    
    void handleState(IContext* context){
        context->setState(LOW);
        handleOffState();
    }
};

class LowStateHandler: public IStateHandler{
    public:
    void handle(){
         std::cout<<"Handling LOW state"<<std::endl;
    }
    
    void handleState(IContext* context){
         context->setState(MODERATE);
         handle();
    }
};

class ModerateStateHandler : public IStateHandler{
    public:
    void handle(){
         std::cout<<"Handling MODERATE state"<<std::endl;
    }
    
    void handleState(IContext* context){
         context->setState(HIGH);
         handle();
    }
};

class HighStateHandler : public IStateHandler{
    public:
    void handle(){
         std::cout<<"Handling HIGH state"<<std::endl;
    }
    
    void handleState(IContext* context){
         context->setState(OFF);
         handle();
    }
};

class StateHandlerFactory : public IStateHandlerFactory{
    map <SwitchState, IStateHandler*> instances;
   
    public :
    StateHandlerFactory(){
        instances[SwitchState::OFF] = new OffStateHandler();
        instances[SwitchState::LOW] = new LowStateHandler();
        instances[SwitchState::MODERATE] = new ModerateStateHandler();
        instances[SwitchState::HIGH] = new HighStateHandler();
        
    }
    
    IStateHandler* create(SwitchState state){
        return instances[state];
    }
       
};

class DigitalSwitch : public IContext{
    private :
    SwitchState currentState ;
    IStateHandler* currentStateHandler;
    IStateHandlerFactory* stateHandlerFactory;

    public:
    DigitalSwitch(int switchState){
      stateHandlerFactory = new  StateHandlerFactory();     
      currentState = static_cast<SwitchState>(switchState);
      currentStateHandler = new OffStateHandler();
    }
    
    void press(){
       currentStateHandler->handleState(this);
    }
    
    SwitchState getState(){
        return static_cast<SwitchState>(currentState);
    }
    
    void setState(SwitchState nextState) {
        currentStateHandler = stateHandlerFactory->create(nextState);
    }
    
    
};
 
int main()
{
    DigitalSwitch switchObj(0);
    switchObj.press();//low
    switchObj.press();//moderate
    switchObj.press();//high
    switchObj.press();//off
    
    switchObj.press();//low
    switchObj.press();//moderate
    switchObj.press();//high
    switchObj.press();//off
    
     switchObj.press();//low
    switchObj.press();//moderate
    switchObj.press();//high
    switchObj.press();//off
    

    
    return 0;
}
