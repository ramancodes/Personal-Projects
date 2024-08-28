package Library.LibraryFunctions;

import java.sql.Connection;

//administrator operations interface
interface AdmOperation {
    boolean addBook(Connection connection);
    boolean removeBook(Connection connection);
    boolean availableBooks(Connection connection);
}
