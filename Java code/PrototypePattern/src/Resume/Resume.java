package Resume;

public class Resume implements Cloneable{
    private String name;
    private String sex;
    private String age;

    private WorkExperience work;

    public Resume(String name){
        this.name = name;
        work = new WorkExperience();
    }

    /*
    * 提供Clone方法调用的私有构造函数，方便克隆"工作经历"的数据
    * */
    public Resume(WorkExperience work){
        this.work = (WorkExperience) work.Clone();
    }
    public void setPersonInfo(String sex, String age){
        this.sex = sex;
        this.age = age;
    }

    public void setWorkExperience(String workDate, String company){
        work.setWorkDate(workDate);
        work.setCompany(company);
    }

    public void display(){
        System.out.println(this.name + " " + this.sex + " " + this.age);
        System.out.println(this.work.getWorkDate() + " " + this.work.getCompany());
    }

    public Object Clone() {
        /*
        * 当字段是引用类型时，普通的Clone方法只复制殷弘但是不复制引用对象，是为浅复制。
        *
        * 深复制：把要复制的对象所引用的对象都复制一遍，即把引用对象的变量指向复制过的新对象，而不是原有的被引用的对象。
        *
        * 调用私有的构造函数，先完成工作经历的克隆，然后再给这份简历对象的相关字段赋值，最终返回一个深复制的简历对象。
        * */
        Resume resume = new Resume(this.work);
        resume.name = this.name;
        resume.age = this.age;
        resume.sex = this.sex;
        return resume;
    }
}
