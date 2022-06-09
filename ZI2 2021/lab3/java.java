import java.math.BigDecimal;
import java.sql.*;
import java.util.Random;

public class java {
    public static void main(String[] args) {
        try {
            System.out.println("Hello World!");

            //Class.forName("org.mariadb.jdbc.Driver");
            String[] arr={"jeden","dwa","trzy","cztery","piec", "szesc","siedem","osiem","dziewiec","dziesiec"};
            Connection conn = DriverManager.getConnection("jdbc:mariadb://localhost/labs?useUnicode=true&serverTimezone=UTC", "root", "");
            Statement statement = conn.createStatement();
            ResultSet rs = statement.executeQuery("select * from lab_2");
          //  PreparedStatement ps=conn.prepareStatement("Insert Into lab_2 (napis,liczba) values(?,?)");
         //   ps.setString(1,"Beka");
         //   ps.setInt(2,864321);
         //   ps.executeUpdate();
            PreparedStatement ps=conn.prepareStatement("Insert into lab_2 set liczba=?,napis=?");
            for(String el:arr){
                int x=new Random().nextInt(100);
                ps.setInt(1,x);
                ps.setString(2,el);
                ps.executeUpdate();
            }
            while (rs.next()) {
                int id = rs.getInt(1);
                String napis = rs.getString("napis");
                BigDecimal liczba = rs.getBigDecimal("liczba");
                System.out.println(id + "-" + napis + "-" + liczba);
            }
        } catch (SQLException ex) {
            System.out.println("Blad operacji na bazie");
            System.out.println(ex.getMessage());

        }
    }
}
