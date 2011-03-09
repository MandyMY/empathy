/*
 * Copyright (C) 2011 Collabora Ltd.
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
 *
 * Authors: Danielle Madeley <danielle.madeley@collabora.co.uk>
 *          Emilio Pozuelo Monfort <emilio.pozuelo@collabora.co.uk>
 */

#ifndef __EMPATHY_ACCOUNT_WIDGET_SKYPE_H__
#define __EMPATHY_ACCOUNT_WIDGET_SKYPE_H__

#include <gtk/gtk.h>
#include <libempathy-gtk/empathy-account-widget.h>

G_BEGIN_DECLS

void empathy_account_widget_build_skype (EmpathyAccountWidget *self,
    const char *filename);
gboolean empathy_account_widget_skype_show_eula (GtkWindow *parent);


G_END_DECLS

#endif /* __EMPATHY_ACCOUNT_WIDGET_SKYPE_H__ */
