/*
 * empathy-account-settings.h - Header for EmpathyAccountSettings
 * Copyright (C) 2009 Collabora Ltd.
 * @author Sjoerd Simons <sjoerd.simons@collabora.co.uk>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef __EMPATHY_ACCOUNT_SETTINGS_H__
#define __EMPATHY_ACCOUNT_SETTINGS_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <libempathy/empathy-account.h>
#include <telepathy-glib/connection-manager.h>

G_BEGIN_DECLS

typedef struct _EmpathyAccountSettings EmpathyAccountSettings;
typedef struct _EmpathyAccountSettingsClass EmpathyAccountSettingsClass;

struct _EmpathyAccountSettingsClass {
    GObjectClass parent_class;
};

struct _EmpathyAccountSettings {
    GObject parent;
    gpointer priv;
};

GType empathy_account_settings_get_type (void);

/* TYPE MACROS */
#define EMPATHY_TYPE_ACCOUNT_SETTINGS \
  (empathy_account_settings_get_type ())
#define EMPATHY_ACCOUNT_SETTINGS(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), \
    EMPATHY_TYPE_ACCOUNT_SETTINGS, EmpathyAccountSettings))
#define EMPATHY_ACCOUNT_SETTINGS_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass), EMPATHY_TYPE_ACCOUNT_SETTINGS, \
    EmpathyAccountSettingsClass))
#define EMPATHY_IS_ACCOUNT_SETTINGS(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj), EMPATHY_TYPE_ACCOUNT_SETTINGS))
#define EMPATHY_IS_ACCOUNT_SETTINGS_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass), EMPATHY_TYPE_ACCOUNT_SETTINGS))
#define EMPATHY_ACCOUNT_SETTINGS_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), EMPATHY_TYPE_ACCOUNT_SETTINGS, \
    EmpathyAccountSettingsClass))

EmpathyAccountSettings * empathy_account_settings_new (
    const gchar *connection_manager,
    const gchar *protocol,
    const char *display_name);

EmpathyAccountSettings * empathy_account_settings_new_for_account (
    EmpathyAccount *account);

gboolean empathy_account_settings_is_ready (EmpathyAccountSettings *settings);

const gchar *empathy_account_settings_get_cm (EmpathyAccountSettings *settings);
const gchar *empathy_account_settings_get_protocol (
    EmpathyAccountSettings *settings);

EmpathyAccount *empathy_account_settings_get_account (
    EmpathyAccountSettings *settings);

gboolean empathy_account_settings_owns_account (
    EmpathyAccountSettings *settings, EmpathyAccount *account);

TpConnectionManagerParam *empathy_account_settings_get_tp_params (
    EmpathyAccountSettings *settings);

void empathy_account_settings_unset (EmpathyAccountSettings *settings,
    const gchar *param);

const GValue *empathy_account_settings_get (EmpathyAccountSettings *settings,
  const gchar *param);

const gchar *
empathy_settings_get_dbus_signature (EmpathyAccountSettings *setting,
  const gchar *param);

const GValue *
empathy_account_settings_get_default (EmpathyAccountSettings *settings,
  const gchar *param);

const gchar *empathy_account_settings_get_string (
    EmpathyAccountSettings *settings,
    const gchar *param);

gint32 empathy_account_settings_get_int32 (EmpathyAccountSettings *settings,
    const gchar *param);
gint64 empathy_account_settings_get_int64 (EmpathyAccountSettings *settings,
    const gchar *param);
guint32 empathy_account_settings_get_uint32 (EmpathyAccountSettings *settings,
    const gchar *param);
guint64 empathy_account_settings_get_uint64 (EmpathyAccountSettings *settings,
    const gchar *param);
gboolean empathy_account_settings_get_boolean (EmpathyAccountSettings *settings,
    const gchar *param);

void empathy_account_settings_set_string (EmpathyAccountSettings *settings,
    const gchar *param, const gchar *value);

void empathy_account_settings_set_int32 (EmpathyAccountSettings *settings,
    const gchar *param, gint32 value);
void empathy_account_settings_set_int64 (EmpathyAccountSettings *settings,
    const gchar *param, gint64 value);
void empathy_account_settings_set_uint32 (EmpathyAccountSettings *settings,
    const gchar *param, guint32 value);
void empathy_account_settings_set_uint64 (EmpathyAccountSettings *settings,
    const gchar *param, guint64 value);

void empathy_account_settings_set_boolean (EmpathyAccountSettings *settings,
    const gchar *param, gboolean value);

const gchar *empathy_account_settings_get_icon_name (
  EmpathyAccountSettings *settings);

const gchar *empathy_account_settings_get_display_name (
  EmpathyAccountSettings *settings);

void empathy_account_settings_set_display_name_async (
  EmpathyAccountSettings *settings,
  const gchar *name,
  GAsyncReadyCallback callback,
  gpointer user_data);

gboolean empathy_account_settings_set_display_name_finish (
  EmpathyAccountSettings *settings,
  GAsyncResult *result,
  GError **error);

void empathy_account_settings_apply_async (EmpathyAccountSettings *settings,
  GAsyncReadyCallback callback,
  gpointer user_data);

gboolean empathy_account_settings_apply_finish (
  EmpathyAccountSettings *settings,
  GAsyncResult *result,
  GError **error);


G_END_DECLS

#endif /* #ifndef __EMPATHY_ACCOUNT_SETTINGS_H__*/
