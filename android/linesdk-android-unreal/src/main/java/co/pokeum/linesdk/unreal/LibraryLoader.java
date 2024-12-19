package co.pokeum.linesdk.unreal;

import android.content.ContentProvider;
import android.content.ContentValues;
import android.database.Cursor;
import android.net.Uri;

import org.jetbrains.annotations.NotNull;

public class LibraryLoader extends ContentProvider {

    // Load Library
    static {
        System.loadLibrary("co_pokeum_linesdk");
    }

    @Override
    public boolean onCreate() {
        return true;
    }

    @Override
    public Cursor query(@NotNull Uri uri, String[] projection, String selection, String[] selectionArgs, String sortOrder) {
        return null;
    }

    @Override
    public String getType(@NotNull Uri uri) {
        return null;
    }

    @Override
    public Uri insert(@NotNull Uri uri, ContentValues values) {
        return null;
    }

    @Override
    public int delete(@NotNull Uri uri, String selection, String[] selectionArgs) {
        return 0;
    }

    @Override
    public int update(@NotNull Uri uri, ContentValues values, String selection, String[] selectionArgs) {
        return 0;
    }
}
