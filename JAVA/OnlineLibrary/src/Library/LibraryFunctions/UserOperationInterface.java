package Library.LibraryFunctions;

import java.sql.Connection;

//user operations interface
interface UserOperationInterface {
    boolean issueBook(Connection connection);
    boolean availableBooks(Connection connection);
    boolean returnBook(Connection connection);
    void myBook();
}
