
package proj6.proj6;

import java.io.File;
import proj6.proj6.MinBitsTest;

public class MinBits {

    static public int findMinBits(File files[]) throws Exception {
        for (File file : files)
            System.out.println(file);
        return 0;
    }

    public static void main(String[] args) {

        File files[] = MinBitsTest.genFiles(5, false);
        MinBits.findMinBits(files);
    }
}

/*
 ********** JAVA
 **************** 
 * show the OUTPUT ********screen shot is OK
 * **************************************
 *********** 
 * use the test case please **************
 * 
 * will be calculating the minimum hash size for a given set of files. sometimes
 * files are indexed by the hash of their content. (git does this for example.)
 * often you only use a subset of the hash for the index. we want to find the
 * minimum prefix bits we need to make sure that each unique file in the given
 * list has a unique hash. "unique file" is an important phrase since the list
 * may have files with duplicate content. if files are duplicates they will (and
 * must) have the same hash, so their hash prefix will also be the same.
 * 
 * spec
 * 
 * we will be using SHA-256 as our hash function. you need to implement the
 * class proj6.MinBits with a single static method:
 * 
 * static public int findMinBits(File files[]) throws Exception
 * 
 * this method will be given a list of File objects and will return the minimum
 * number of bits to guarantee unique hashes for each file.
 * 
 * i've included a test case MinBitsTest.javaPreview the document that will test
 * your code. some of the test cases will also include files with duplicate
 * content. (when grading, two more unit tests will be included to ensure that
 * your code don't only work with these test cases.) i'm using Random with a
 * specified seed, so the set of test files should be deterministic even though
 * they are created with a random function.
 * 
 * TEST CASE *******
 * 
 * package proj6.proj6;
 * 
 * import org.junit.Assert;
 * 
 * import org.junit.Test;
 * 
 * import org.junit.runner.RunWith;
 * 
 * import org.junit.runners.Parameterized;
 * 
 * import proj6.MinBits;
 * 
 * import java.io.File;
 * 
 * import java.io.IOException;
 * 
 * import java.nio.file.Files;
 * 
 * import java.util.ArrayList;
 * 
 * import java.util.Arrays;
 * 
 * import java.util.Collection;
 * 
 * import java.util.Random;
 * 
 * @RunWith(Parameterized.class)
 * 
 * public class MinBitsTest {
 */
/**
 * 
 * this function will deterministically generate a random set of
 * 
 * files
 * 
 * based on the seed, which is also the file count. java spec says
 * 
 * that
 * 
 * the Random calculations should be the same across all
 * 
 * implementations
 * 
 * for the same seed.
 *
 * 
 * 
 * if duplicates are enabled, on average every 10 files we will pick
 * 
 * some
 * 
 * bytes to duplicate and on average the duplicate bytes will be used
 * 
 * every 4th file.
 *
 * 
 * 
 * @param fileCount the number of files to generate.
 * 
 * @param duplicate should there be duplicates?
 * 
 * @return
 * 
 * @throws IOException
 * 
 */
/*
 * static public File[] genFiles(int fileCount, boolean duplicate) throws
 * 
 * IOException {
 * 
 * Random rand = new Random(fileCount);
 * 
 * ArrayList<File> files = new ArrayList<>();
 * 
 * byte duplicateBytes[] = null;
 * 
 * for (int i = 0; i < fileCount; i++) {
 * 
 * byte buffer[] = new byte[rand.nextInt(65*1024)];
 * 
 * int size = rand.nextInt(buffer.length);
 * 
 * rand.nextBytes(buffer);
 * 
 * if (duplicate) {
 * 
 * if (rand.nextInt(10) == 0) {
 * 
 * duplicateBytes = buffer;
 * 
 * } else if (duplicateBytes != null && rand.nextInt(4) == 0)
 * 
 * {
 * 
 * buffer = duplicateBytes;
 * 
 * }
 * 
 * }
 */