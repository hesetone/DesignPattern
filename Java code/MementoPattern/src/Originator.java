public class Originator {
    private String mState;

    public String getState() {
        return mState;
    }
    public void setState(String state){
        mState = state;
    }

    public Memento createMemento(){
        return (new Memento(mState));
    }

    public void setMemento(Memento memento){
        mState = memento.getState();
    }

    public void show(){
        System.out.println("State=" + mState);
    }
}
