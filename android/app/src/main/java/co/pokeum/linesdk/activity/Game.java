package co.pokeum.linesdk.activity;

import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.os.Bundle;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import co.pokeum.linesdk.databinding.ActivityMainBinding;

public abstract class Game extends AppCompatActivity {

    protected static final String LINE_SDK_TAG = "LineSDK";

    protected ActivityMainBinding binding;

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        gameActivityOnActivityResultAdditions(requestCode, resultCode, data);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        gameActivityOnCreateAdditions();

        // Read metadata from AndroidManifest.xml
        try {
            ApplicationInfo ai = getPackageManager().getApplicationInfo(getPackageName(), PackageManager.GET_META_DATA);
            Bundle bundle = ai.metaData;
            gameActivityReadMetadata(bundle);
        }
        catch (Throwable ignore) { }

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        initUI();
    }

    @Override
    protected void onStart() {
        super.onStart();
        gameActivityOnStartAdditions();
    }

    @Override
    protected void onResume() {
        super.onResume();
        gameActivityOnResumeAdditions();
    }

    @Override
    protected void onPause() {
        super.onPause();
        gameActivityOnPauseAdditions();
    }

    @Override
    protected void onNewIntent(Intent intent) {
        super.onNewIntent(intent);
        gameActivityOnNewIntentAdditions(intent);
    }

    @Override
    protected void onStop() {
        super.onStop();
        gameActivityOnStopAdditions();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        gameActivityOnDestroyAdditions();
    }

    //=========================================================================================================//

    protected abstract void gameActivityReadMetadata(Bundle bundle);
    protected abstract void gameActivityOnCreateAdditions();
    protected abstract void gameActivityOnDestroyAdditions();
    protected abstract void gameActivityOnStartAdditions();
    protected abstract void gameActivityOnStopAdditions();
    protected abstract void gameActivityOnPauseAdditions();
    protected abstract void gameActivityOnResumeAdditions();
    protected abstract void gameActivityOnNewIntentAdditions(Intent newIntent);
    protected abstract void gameActivityOnActivityResultAdditions(int requestCode, int resultCode, Intent data);

    //=========================================================================================================//

    protected abstract void initUI();
}