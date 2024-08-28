package Library.UserEncryption;

import Library.LibraryFunctions.ConnectionToDB;

import java.sql.*;

class DatabaseOperations {
    boolean Login(Integer userAdmin, String libID, String pass, Connection connection){
        String sql = null;
        if(userAdmin==1){
            sql = "SELECT UserID FROM UserDetails WHERE UserID = '"+libID+"' AND pass = '"+pass+"';"; //user
        } else if (userAdmin ==2) {
            sql = "SELECT AdminID FROM AdminDetails WHERE AdminID = '"+libID+"' AND Pass = '"+pass+"';"; //admin
        }

        try {
            if(!check(connection, sql)){
                return false;
            }
            else {
                return true;
            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    boolean Registration(Integer userAdmin, String Name, String libID, String pass, Connection connection){
        String sql = null, sql2 = null;
        if(userAdmin==1){
            sql = "INSERT INTO UserDetails(UserID, Name, Pass) VALUES('"+libID+"', '"+Name+"', '"+pass+"');"; //user
        } else if (userAdmin ==2) {
            sql = "INSERT INTO AdminDetails(AdminID, Name, Pass) VALUES('"+libID+"', '"+Name+"', '"+pass+"');"; //admin
        }

        try {
            update(connection, sql);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        if(userAdmin==1){
            sql2 = "SELECT UserID FROM UserDetails WHERE UserID = '"+libID+"' AND pass = '"+pass+"';"; //user
        } else if (userAdmin ==2) {
            sql2 = "SELECT AdminID FROM AdminDetails WHERE AdminID = '"+libID+"' AND Pass = '"+pass+"';"; //admin
        }

        try {
            if(!check(connection, sql2)){
                System.out.println("Wrong Credentials");
                return false;
            }
            else {
                System.out.println("Registration Successful");
                return true;
            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }



    void update(Connection connection, String sql) throws SQLException {
        Statement statement = connection.createStatement();
        statement.execute(sql);
    }


    boolean check(Connection connection, String sql) throws SQLException {
        Statement statement = connection.createStatement();
        ResultSet resultSet = statement.executeQuery(sql);
        return resultSet.next();
    }

//    public static void main(String[] args) {
//        DatabaseOperations databaseOperations = new DatabaseOperations();
//        Connection connection = ConnectionToDB.connectLibrary();
//        if(databaseOperations.Login(1, "raman15", "ramanhere", connection)){
//            System.out.println("Successful");
//        }
//        else {
//            System.out.println("Not Successful");
//        }
//    }
}
