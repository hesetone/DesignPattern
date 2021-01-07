public class Main {
    public static void main(String[] args){
        Operation oper;
        oper = SimpleFactory.createOperate("/");
        oper.setNumberA(1);
        oper.setNumberB(2);
        double result = oper.getResult();
        System.out.println(result);
    }
}
