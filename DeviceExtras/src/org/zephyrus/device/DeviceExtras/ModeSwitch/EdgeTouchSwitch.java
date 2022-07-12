package org.zephyrus.device.DeviceExtras;

import android.content.Context;
import android.content.SharedPreferences;
import androidx.preference.Preference;
import androidx.preference.Preference.OnPreferenceChangeListener;

import org.zephyrus.device.DeviceExtras.DeviceExtras;

public class EdgeTouchSwitch implements OnPreferenceChangeListener {

    private static final String FILE = "/proc/touchpanel/oplus_tp_limit_enable";

    public static String getFile() {
        if (FileUtils.fileWritable(FILE)) {
            return FILE;
        }
        return null;
    }

    public static boolean isSupported() {
        return FileUtils.fileWritable(getFile());
    }

    public static boolean isCurrentlyEnabled(Context context) {
        return FileUtils.getFileValueAsBoolean(getFile(), true);
    }

    @Override
    public boolean onPreferenceChange(Preference preference, Object newValue) {
        Boolean enabled = (Boolean) newValue;
        FileUtils.writeValue(getFile(), enabled ? "1" : "0");
        return true;
    }
}
