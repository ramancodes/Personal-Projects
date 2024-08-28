package Library.UserEncryption;

import java.sql.*;

class Demo {
    public Demo() throws SQLException {
//        String sql = "CREATE TABLE UserDetails(UserID VARCHAR(50) PRIMARY KEY, Name VARCHAR(50), Pass VARCHAR(50), BookID INT, FOREIGN KEY(BookID) REFERENCES Books(BookID) ON DELETE SET NULL);";
//        String sql = "CREATE TABLE AdminDetails(AdminID VARCHAR(50) PRIMARY KEY, Name VARCHAR(50), Pass VARCHAR(50));";
//            String sql = "";
//        String sql1 = "INSERT INTO UserDetails VALUES" +
//                "(102, 'Shyam')," +
//                "(103, 'Rahul')," +
//                "(104, 'Amit')," +
//                "(105, 'Amar')," +
//                "(106, 'Sneha');";
//        String sql2 = "SELECT * FROM UserDetails";
//        String sql = "INSERT INTO UserDetails VALUES('raman15', 'Raman', 'ramanhere', 1206);";
//        String sql = "INSERT INTO AdminDetails VALUES('raman15', 'Raman', 'ramanhere');";


        String url = "jdbc:sqlite:Library.db";
        Connection connection = null;
//        ResultSet resultSet = null;
        connection = DriverManager.getConnection(url);
        Statement statement = connection.createStatement();
//        resultSet = statement.executeQuery(sql);
//            while (resultSet.next()){
//                System.out.println("User Id : "+ resultSet.getInt(1)+ "\nName : "+resultSet.getString(2));
//            }
//            if(resultSet.next()==false){
//                System.out.println("No Details Found");
//            }
//        statement.execute(sql);
    }

//    public static void main(String[] args) {
//        try {
//            Demo demo = new Demo();
//            System.out.println("Successful!!");
//        } catch (SQLException e) {
//            throw new RuntimeException(e);
//        }
//    }
}
