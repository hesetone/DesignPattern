public class Main {
    /*
    * @author wsh-nie
    * */
    public static void main(String[] args){
        ConcreteSubject concreteSubject = new ConcreteSubject("阿珍");

        ConcreteObserver a = new ConcreteObserver(concreteSubject,"小北");
        ConcreteObserver b = new ConcreteObserver(concreteSubject,"小东");
        ConcreteObserver c = new ConcreteObserver(concreteSubject,"小西");

        concreteSubject.attach(a);
        concreteSubject.attach(b);
        concreteSubject.attach(c);

        concreteSubject.setSubjectState("烦恼");
        concreteSubject.Notify();//观察对象通知所有观察者。
        System.out.println("************************************");
        concreteSubject.detach(b);
        concreteSubject.Notify();
        System.out.println("************************************");
        concreteSubject.setSubjectState("开心");
        concreteSubject.Notify();
        System.out.println("观察者"+ a.getName() + "正在观察的对象: "+a.getSubject().getName());
    }
}
