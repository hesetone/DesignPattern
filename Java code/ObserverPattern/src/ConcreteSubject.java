public class ConcreteSubject extends Subject{
    private String mName;
    private String mSubjectState;
    /*
    * @author wsh-nie
    *
    * 具体对象，公布当前状态，并设置新状态
    * */
    public ConcreteSubject(String name){
        this.mName = name;
    }

    public String getName(){
        return this.mName;
    }

    public String getSubjectState(){
        return mSubjectState;
    }

    public void setSubjectState(String subjectState){
        this.mSubjectState = subjectState;
    }
}
