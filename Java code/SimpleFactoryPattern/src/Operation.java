/**
 * 数据运算基类，定义两个私有成员，定义计算方法
 *
 * @author wsh-nie
 *
 * */

public class Operation {
    private double _numberA = 0;
    private double _numberB = 0;
    public double getNumberA(){
        return _numberA;
    }
    public  void setNumberA(double numberA){
        this._numberA = numberA;
    }
    public double getNumberB(){
        return _numberB;
    }
    public void setNumberB(double numberB){
        this._numberB = numberB;
    }
    public double getResult(){
        double result = 0;
        return result;
    }
}
