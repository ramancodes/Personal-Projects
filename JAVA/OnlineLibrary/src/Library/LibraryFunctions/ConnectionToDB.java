package Library.LibraryFunctions;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class ConnectionToDB {
    //method to connect to the database for storing the details of the books
    public static Connection connectLibrary(){
        String url = "jdbc:sqlite:Library.db";
        Connection conn = null;
        try {
            conn = DriverManager.getConnection(url);
        } catch (SQLException e) {
            System.out.println("Error Connecting To database");
            System.out.println(e.getMessage());
        }
        return conn;
    }
}
