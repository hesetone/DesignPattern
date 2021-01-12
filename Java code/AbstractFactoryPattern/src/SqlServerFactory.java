public class SqlServerFactory implements IFactory{

    public IUser createUser(){
        return new SqlServerUser();
    }

    public IDepartment createDepartment(){
        return new SqlServerDepartment();
    }
}
