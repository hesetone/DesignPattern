public class Singleton {
    /*
    * @author wsh-nie
    * 类内定义静态类对象，并将构造函数private，然后通过getInstance方法
    * */
    private static Singleton mSingleton;

    private Singleton(){

    }

    public static Singleton getInstance(){
        if(mSingleton == null){
            mSingleton = new Singleton();
        }
        return  mSingleton;
    }
}
