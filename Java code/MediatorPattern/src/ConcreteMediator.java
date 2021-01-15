public class ConcreteMediator extends Mediator{
    private ConcreteColleagueA colleagueA;
    private ConcreteColleagueB colleagueB;

    public void setColleagueA(ConcreteColleagueA colleagueA){
        this.colleagueA = colleagueA;
    }

    public void setColleagueB(ConcreteColleagueB colleagueB){
        this.colleagueB = colleagueB;
    }

    /*
    * @Override
    * 根据对象选择做出判断，通知对象
    */
    public void send(String message, Colleague colleague) {
        if(colleague == this.colleagueA){
            colleagueB.Notify(message);
        }else{
            colleagueA.Notify(message);
        }
    }
}
