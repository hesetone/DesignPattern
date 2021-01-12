public class SqlServerDepartment implements IDepartment{
    public void Insert(Department department){
        System.out.println("在SQL Server中给Department表增加一条记录");
    }
    public Department getDepartment(String name){
        System.out.println("在SQL Server中根据name得到Department表一条数据");
        return null;
    }
}
