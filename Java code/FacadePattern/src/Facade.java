public class Facade {
    SubSystemOne one;
    SubSystemTwo two;
    SubSystemThree three;

    public Facade(){
        one = new SubSystemOne();
        two = new SubSystemTwo();
        three = new SubSystemThree();
    }

    public void methodA(){
        System.out.println("方法组A: ");
        one.methodOne();
        two.methodTwo();
    }

    public void methodB(){
        System.out.println("方法组B: ");
        two.methodTwo();
        three.methodThree();
    }
}
