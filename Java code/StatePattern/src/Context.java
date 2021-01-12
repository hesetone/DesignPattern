public class Context {
    private State mState;
    public Context(State state){
        this.mState = state;
    }

    public State getState(){
        return this.mState;
    }

    public void setState(State state){
        this.mState = state;
        System.out.println("当前状态：" + this.mState.getClass().getName());
    }

    public void request(){
        this.mState.Handle(this);
    }

}
