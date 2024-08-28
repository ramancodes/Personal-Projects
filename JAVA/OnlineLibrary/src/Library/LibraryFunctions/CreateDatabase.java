package Library.LibraryFunctions;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

class CreateDatabase {

    //method to insert a new book
    boolean insertValues(Integer BookID, String BookName, String Author, Integer Availability, Connection connection){
        String sql = "INSERT INTO Books (BookID,BookName,Author,Availability)" +
                "VALUES ("+BookID+",'"+BookName+"','"+Author+"',"+Availability+");";
        runSQLQueries(sql, connection);
        return true;
    }

    //method to update the details of a book while issuing and returning
    boolean updateValue(Integer BookID, Integer Availability, Connection connection){
            String sql = "UPDATE Books set Availability = " + Availability + " WHERE BookID = " + BookID + ";";
            runSQLQueries(sql, connection);
            return true;
    }

    //method to delete a book from the library
    boolean deleteValue(Integer BookID, Connection connection){
        String sql = "DELETE FROM Books WHERE BookID = "+BookID+";";
        runSQLQueries(sql, connection);
        System.out.println("Deleted");
        return true;
    }

    //run sql commands
    void runSQLQueries(String sql, Connection connection){
        try {
            if(connection.isValid(3)) {
                Statement smt = connection.createStatement();
                smt.execute(sql);
            }
        } catch (SQLException e) {
            System.out.println("\n*Error in connection while running queries*");
            throw new RuntimeException(e);
        }
    }
}

class AccessDatabase {
    //method to show all the books
    void showValues(Connection connection) {
        String sql = "SELECT * FROM Books;";
        runSQLQueries(sql, connection);
    }

    //method to show a single book
    void showSingleValue(Integer BookID, Connection connection) {
        String sql = "SELECT * FROM Books WHERE BookID = " + BookID + ";";
        runSQLQueriesSingle(sql, connection);
    }

    //run sql commands
    void runSQLQueries(String sql, Connection connection) {
        try {
            if (connection.isValid(3)) {
                Statement smt = connection.createStatement();
                ResultSet resultSet = smt.executeQuery(sql);
                System.out.println("-------------------------------------------------------------");
                System.out.println("Book ID" + "  |  " + "BookName" + "  |  " + "Author Name" + "  |  " + "Available");
                if (resultSet.next() == false) {
                    System.out.println("No books available currently");
                }
                while (resultSet.next()) {
                    Integer bookID = resultSet.getInt("BookID");
                    String bookName = resultSet.getString("BookName");
                    String authorName = resultSet.getString("Author");
                    Integer availability = resultSet.getInt("Availability");

                    System.out.println(bookID + "  |  " + bookName + "  |  " + authorName + "  |  " + availability);
                }

                System.out.println("-------------------------------------------------------------");
            }
        } catch (SQLException e) {
            System.out.println("\n*Error in connection while running queries*");
            throw new RuntimeException(e);
        }
    }

    //run sql commands for single value
    void runSQLQueriesSingle(String sql, Connection connection) {
        try {
            if (connection.isValid(3)) {
                Statement smt = connection.createStatement();
                ResultSet resultSet = smt.executeQuery(sql);
                System.out.println("-------------------------------------------------------------");
                System.out.println("Book ID" + "  |  " + "BookName" + "  |  " + "Author Name" + "  |  " + "Available");
                if (resultSet.next() == false) {
                    System.out.println("---No books available currently---");
                }
//                while (resultSet.next()){
                Integer bookID = resultSet.getInt("BookID");
                String bookName = resultSet.getString("BookName");
                String authorName = resultSet.getString("Author");
                Integer availability = resultSet.getInt("Availability");

                System.out.println(bookID + "  |  " + bookName + "  |  " + authorName + "  |  " + availability);
//                }

                System.out.println("-------------------------------------------------------------");
            }
        } catch (SQLException e) {
            System.out.println("\n*Error in connection while running queries*");
            throw new RuntimeException(e);
        }
    }
}
