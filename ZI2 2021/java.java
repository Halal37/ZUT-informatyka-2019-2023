import java.math.BigDecimal;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class App{
    public static void main(String[] args) throws Exception{
        System.out.println("Hello World!");

        Class.forName("org.mariadb.jdbc.Driver");

        Connection conn=DriverManager.getConnection("jdbc:mariadb://localhost/labs?useUnicode=true&serverTimezone=UTC","root","");
        Statement statement=conn.createStatement();
        ResultSet rs=statement.executeQuery("select * from customers");

        while(rs.next()){
            int id=rs.getInt(1);
            String name= rs.getString("customerName");
            BigDecimal limit = rs.getBigDecimal("creditLimit");
            System.out.println(id+ "-"+name+"-"+ limit);
        }
    }
}