package proj6.proj6;

import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import proj6.MinBits;
import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Random;

@RunWith(Parameterized.class)
public class MinBitsTest {

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

    static public File[] genFiles(int fileCount, boolean duplicate) throws

    IOException {

        Random rand = new Random(fileCount);

        ArrayList<File> files = new ArrayList<>();

        byte duplicateBytes[] = null;

        for (int i = 0; i < fileCount; i++) {

            byte buffer[] = new byte[rand.nextInt(65 * 1024)];

            int size = rand.nextInt(buffer.length);

            rand.nextBytes(buffer);

            if (duplicate) {

                if (rand.nextInt(10) == 0) {

                    duplicateBytes = buffer;

                } else if (duplicateBytes != null && rand.nextInt(4) == 0) {

                    buffer = duplicateBytes;
                }
            }
        }
    }
}