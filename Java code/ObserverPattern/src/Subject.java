import java.util.ArrayList;
import java.util.List;

public abstract class Subject {
    /*
     * @author wsh-nie
     * 一个对象可以有多个观察者，同时需要维护观察者增减，以及更新时通知所有观察者
     * */
    private List<Observer> observers = new ArrayList<Observer>();

    public void attach(Observer observer){
        this.observers.add(observer);
    }

    public void detach(Observer observer){
        this.observers.remove(observer);
    }

    public void Notify(){
        for (Observer o:observers) {
            o.update();
        }
    }
}
