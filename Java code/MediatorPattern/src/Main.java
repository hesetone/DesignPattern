public class Main {
    public static void main(String[] args){
        ConcreteMediator m = new ConcreteMediator();

        ConcreteColleagueA ca = new ConcreteColleagueA(m);
        ConcreteColleagueB cb = new ConcreteColleagueB(m);

        m.setColleagueA(ca);
        m.setColleagueB(cb);

        ca.send("吃饭没？");
        cb.send("吃的馍馍！");
    }
}
