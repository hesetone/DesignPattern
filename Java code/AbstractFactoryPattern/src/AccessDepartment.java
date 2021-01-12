public class AccessDepartment implements IDepartment{

    public void Insert(Department department){
        System.out.println("在Access中给Department表增加一条记录");
    }
    public Department getDepartment(String name){
        System.out.println("在Access中根据name得到Department表一条数据");
        return null;
    }
}
