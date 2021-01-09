public class Main {
    public static void main(String[] args){
        Factory operFactory = new DivFactory();//这里选择实例化对象
        Operation oper = operFactory.createOperation();
        oper.setNumberA(1);
        oper.setNumberB(0);
        double result = oper.getResult();
        System.out.println(result);
    }
}
