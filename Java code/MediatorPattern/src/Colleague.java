public abstract class Colleague {
    protected Mediator mediator;
    public Colleague(Mediator mediator){
        this.mediator = mediator;
    }

    public void Notify(String message){
        System.out.println(this.getClass().toString() + " get message: " + message);
    }

    public void send(String message){
        /*
        * @author wsh-nie
        * 中介者发出信息
        * */
        mediator.send(message,this);
    }
}
