public class ConcreteObserver extends Observer {
    private String mName;//观察者名字
    private String mObserverState;//观察者观察到观察对象的状态
    private ConcreteSubject mSubject;//观察对象

    /*
    * @author wsh-nie
    * 构造函数初始化观察对象
    * */
    public ConcreteObserver(ConcreteSubject subject, String name){
        mSubject = subject;
        mName = name;
    }

    public String getName(){
        return this.mName;
    }

    @Override
    public void update() {
        /*
        * 获取观察对象的当前状态，并输出
        * */
        mObserverState  = mSubject.getSubjectState();
        String state = String.format("观察者%s观察到观察对象当前最新状态是%s",this.mName,mObserverState);
        System.out.println(state);
    }

    public ConcreteSubject getSubject(){
        /*
        * 输出当前观察者观察的对象
        * */
        return this.mSubject;
    }
}
