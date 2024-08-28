package Package1;

import java.io.File;
import java.io.FileNotFoundException;

public class CreateNewDatabaseFile {
    CreateNewDatabaseFile(){
            File obj = new File("Library.txt");
            if(obj.exists()) {
                System.out.println("File Found");
            }
            else {
                System.out.println("File Not Found");
            }
    }

    public static void main(String[] args) {
        CreateNewDatabaseFile createNewDatabaseFile = new CreateNewDatabaseFile();
    }
}
