package Library.LibraryFunctions;

import java.sql.Connection;

public class StartLibrary {
    public StartLibrary(Integer userAdmin, Connection connection){
        CallingLibraryFunctions callingLibraryFunctions = new CallingLibraryFunctions(userAdmin, connection);
    }
}
