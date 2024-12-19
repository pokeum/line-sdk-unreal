plugins {
    id("com.android.library")
    id("org.jetbrains.kotlin.android")
    id("maven-publish")
}

android {
    namespace = "co.pokeum.linesdk.unrealwrapper"
    compileSdk = 31

    defaultConfig {
        minSdk = 19
        testInstrumentationRunner = "androidx.test.runner.AndroidJUnitRunner"
    }

    buildTypes {
        release {
            isMinifyEnabled = false
            proguardFiles(
                getDefaultProguardFile("proguard-android-optimize.txt"),
                "proguard-rules.pro"
            )
        }
    }
    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_1_8
        targetCompatibility = JavaVersion.VERSION_1_8
    }
    kotlinOptions {
        jvmTarget = JavaVersion.VERSION_1_8.toString()
    }
}

/* -------------------------------------------------------------------------------------------------
    JAVA_HOME=$JAVA_17_HOME &&\
    ./gradlew clean &&\
    ./gradlew :linesdk-android-unreal-wrapper:publishReleasePublicationToLocalRepository
 ------------------------------------------------------------------------------------------------- */
publishing {
    repositories {
        maven {
            name = "Local"
            url = uri("file://${buildDir}/repository")
        }
    }
    publications {
        create<MavenPublication>("release") {
            groupId = "co.pokeum.linesdk.unrealwrapper"
            artifactId = "linesdk-android-unreal-wrapper"
            version = "1.0.0"

            afterEvaluate {
                from(components["release"])
            }
        }
    }
}

dependencies {
    compileOnly(project(":linesdk-android-unreal"))

    val lineSdkVersion = "5.10.1"
    implementation("com.linecorp.linesdk:linesdk:$lineSdkVersion")

    implementation("com.google.code.gson:gson:2.10.1")
}