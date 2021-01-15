import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args){
        ConcreteHandlerA h1 = new ConcreteHandlerA();
        ConcreteHandlerB h2 = new ConcreteHandlerB();
        ConcreteHandlerC h3 = new ConcreteHandlerC();

        /*
        * @author wsh-nie
        * 设置链表结构
        * */
        h1.setSuccessor(h2);
        h2.setSuccessor(h3);

        List<Integer> lst = new ArrayList<Integer>();

        for(int i = 0; i < 10; i++){
            lst.add((int)(Math.random() * 39));
        }

        //System.out.println(lst.toString());

        for(int i = 0; i < 10; i++){
            h1.handlerRequest(lst.get(i));
        }
    }
}
