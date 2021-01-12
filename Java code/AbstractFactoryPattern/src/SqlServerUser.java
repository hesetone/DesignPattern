public class SqlServerUser implements IUser{

    public void Insert(User user){
        System.out.println("在SQL Server中给User表增加一条记录");
    }

    public User getUser(int id){
        User user = null;
        System.out.println("在SQL Server中根据ID得到User表一条数据");
        return null;
    }
}
