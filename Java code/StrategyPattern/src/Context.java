public class Context {
    Strategy mStrategy;

    public Context(Strategy strategy){
        /**
         * 构造函数
         * 初始化时，传入具体的策略对象
         * */
        mStrategy = strategy;
    }

    public void contextInterFace(){
        /**
         * 根据具体的对象，调用其算法的方法
         * */
        mStrategy.algorithmInterface();
    }
}
