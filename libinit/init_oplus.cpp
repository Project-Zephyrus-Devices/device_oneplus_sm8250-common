/*
 * Copyright (C) 2022 The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include <android-base/logging.h>
#include <android-base/properties.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

using android::base::GetProperty;

/*
 * SetProperty does not allow updating read only properties and as a result
 * does not work for our use case. Write "OverrideProperty" to do practically
 * the same thing as "SetProperty" without this restriction.
 */
void OverrideProperty(const char* name, const char* value) {
    size_t valuelen = strlen(value);

    prop_info* pi = (prop_info*)__system_property_find(name);
    if (pi != nullptr) {
        __system_property_update(pi, value, valuelen);
    } else {
        __system_property_add(name, strlen(name), value, valuelen);
    }
}

/*
 * Only for read-only properties. Properties that can be wrote to more
 * than once should be set in a typical init script (e.g. init.oplus.hw.rc)
 * after the original property has been set.
 */
void vendor_load_properties() {
    auto prj_version = std::stoi(GetProperty("ro.boot.prj_version", "0"));
    auto rf_version = std::stoi(GetProperty("ro.boot.rf_version", "0"));

    switch (prj_version) {
        case 19821:
        OverrideProperty("ro.vendor.usb.name", "OnePlus 8");
      /* OnePlus 8 */
      switch (rf_version){
        case 11:
          /* China */
          OverrideProperty("ro.product.model", "IN2010");
          break;
        case 13:
          /* India */
          OverrideProperty("ro.product.model", "IN2011");
          break;
        case 14:
          /* Europe */
          OverrideProperty("ro.product.model", "IN2013");
          break;
        case 15:
          /* Global / US Unlocked */
          OverrideProperty("ro.product.model", "IN2015");
          break;
        default:
          /* Generic */
          OverrideProperty("ro.product.model", "IN2015");
          break;
      }
      break;
    case 19855:
    OverrideProperty("ro.vendor.usb.name", "OnePlus 8");
      /* OnePlus 8 T-Mobile */
      switch (rf_version){
        case 12:
          /* T-Mobile */
          OverrideProperty("ro.product.model", "IN2017");
          break;
        default:
          /* Generic */
          OverrideProperty("ro.product.model", "IN2015");
          break;
      }
      break;
    case 19867:
    OverrideProperty("ro.vendor.usb.name", "OnePlus 8");
      /* OnePlus 8 Verizon */
      switch (rf_version){
        case 25:
          /* Verizon */
          OverrideProperty("ro.product.model", "IN2019");
          break;
        default:
          /* Generic */
          OverrideProperty("ro.product.model", "IN2015");
          break;
      }
      break;
    case 19811:
    OverrideProperty("ro.vendor.usb.name", "OnePlus 8 Pro");
      /* OnePlus 8 Pro */
      switch (rf_version){
        case 11:
          /* China */
          OverrideProperty("ro.product.model", "IN2020");
          break;
        case 13:
          /* India */
          OverrideProperty("ro.product.model", "IN2021");
          break;
        case 14:
          /* Europe */
          OverrideProperty("ro.product.model", "IN2023");
          break;
        case 15:
          /* Global / US Unlocked */
          OverrideProperty("ro.product.model", "IN2025");
          break;
        default:
          /* Generic */
          OverrideProperty("ro.product.model", "IN2025");
          break;
      }
      break;
      case 19805:
      OverrideProperty("ro.vendor.usb.name", "OnePlus 8T");
      /* OnePlus 8T */
      switch (rf_version){
        case 11:
          /* China */
          OverrideProperty("ro.product.model", "KB2000");
          break;
        case 13:
          /* India */
          OverrideProperty("ro.product.model", "KB2001");
          break;
        case 14:
          /* Europe */
          OverrideProperty("ro.product.model", "KB2003");
          break;
        case 15:
          /* Global / US Unlocked */
          OverrideProperty("ro.product.model", "KB2005");
          break;
        default:
          /* Generic */
          OverrideProperty("ro.product.model", "KB2005");
          break;
      }
      break;
    case 20809:
    OverrideProperty("ro.vendor.usb.name", "OnePlus 8T");
      /* OnePlus 8T T-Mobile */
      switch (rf_version){
        case 12:
          /* T-Mobile */
          OverrideProperty("ro.product.model", "KB2007");
          break;
        default:
          /* Generic */
          OverrideProperty("ro.product.model", "KB2005");
          break;
      }
      break;
     case 20828:
      /* OnePlus 9R */
      OverrideProperty("ro.vendor.usb.name", "OnePlus 9R");
      switch (rf_version){
      case 11:
          /* China */
          OverrideProperty("ro.product.model", "LE2100");
          break;
      case 13:
          /* India */
          OverrideProperty("ro.product.model", "LE2101");
          break;
      default:
          /* Generic */
          OverrideProperty("ro.product.model", "LE2101");
          break;
      }
      break;
    }
}
