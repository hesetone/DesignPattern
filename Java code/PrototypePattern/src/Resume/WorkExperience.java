package Resume;

public class WorkExperience implements Cloneable{
    private String workDate;
    private String company;

    public void setWorkDate(String timeArea){
        this.workDate = timeArea;
    }

    public String getWorkDate(){
        return workDate;
    }

    public void setCompany(String company) {
        this.company = company;
    }

    public String getCompany() {
        return company;
    }

    public Object Clone(){
        Object obj = null;
        try{
            obj = clone();
        }catch(CloneNotSupportedException e){
            e.printStackTrace();
        }
        return obj;
    }
}
