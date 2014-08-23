<?php
/**
 * @file
 * site_template_feature.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function site_template_feature_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'footer';
  $mini->category = 'Coral';
  $mini->admin_title = 'Footer';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1a549706-d58e-429b-91ff-a8d01e4f2e75';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2780fe8a-035e-4e0a-bb9e-2b290d079486';
    $pane->panel = 'middle';
    $pane->type = 'panels_mini';
    $pane->subtype = 'footer_menus';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grid-13',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2780fe8a-035e-4e0a-bb9e-2b290d079486';
    $display->content['new-2780fe8a-035e-4e0a-bb9e-2b290d079486'] = $pane;
    $display->panels['middle'][0] = 'new-2780fe8a-035e-4e0a-bb9e-2b290d079486';
    $pane = new stdClass();
    $pane->pid = 'new-d077cf8b-e36a-46b2-b4a9-0e52da62b842';
    $pane->panel = 'middle';
    $pane->type = 'coral_footer';
    $pane->subtype = 'coral_footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grid-11-last',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'd077cf8b-e36a-46b2-b4a9-0e52da62b842';
    $display->content['new-d077cf8b-e36a-46b2-b4a9-0e52da62b842'] = $pane;
    $display->panels['middle'][1] = 'new-d077cf8b-e36a-46b2-b4a9-0e52da62b842';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-2780fe8a-035e-4e0a-bb9e-2b290d079486';
  $mini->display = $display;
  $export['footer'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'footer_menus';
  $mini->category = 'Coral';
  $mini->admin_title = 'Footer menus';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'ea2455a8-f035-4a9b-a734-a5346dcbdff4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-337b0143-0512-4531-9a98-b8a5b69e6f16';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'menu-general';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'General',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '337b0143-0512-4531-9a98-b8a5b69e6f16';
    $display->content['new-337b0143-0512-4531-9a98-b8a5b69e6f16'] = $pane;
    $display->panels['left'][0] = 'new-337b0143-0512-4531-9a98-b8a5b69e6f16';
    $pane = new stdClass();
    $pane->pid = 'new-1dc09c84-9106-49d0-a66f-50b4b005affc';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'menu-documentation';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Documentation',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1dc09c84-9106-49d0-a66f-50b4b005affc';
    $display->content['new-1dc09c84-9106-49d0-a66f-50b4b005affc'] = $pane;
    $display->panels['right'][0] = 'new-1dc09c84-9106-49d0-a66f-50b4b005affc';
    $pane = new stdClass();
    $pane->pid = 'new-1c4eb6e4-6049-4dbc-89ae-25154b0bbff4';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'menu-account';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Account',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1c4eb6e4-6049-4dbc-89ae-25154b0bbff4';
    $display->content['new-1c4eb6e4-6049-4dbc-89ae-25154b0bbff4'] = $pane;
    $display->panels['right'][1] = 'new-1c4eb6e4-6049-4dbc-89ae-25154b0bbff4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['footer_menus'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'getting_help';
  $mini->category = 'Coral';
  $mini->admin_title = 'Getting help';
  $mini->admin_description = 'A help section display that will open into a popup. Triggered by the click event of the Getting help link.';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'top' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '662368e5-fa6c-40db-802e-ab1342008e97';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7f4b7eb1-f562-448a-a3a1-83d48d2d83c2';
    $pane->panel = 'bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Help footer',
      'title' => '',
      'body' => '<div class=\'getting-help-footer\'>&nbsp;</div>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7f4b7eb1-f562-448a-a3a1-83d48d2d83c2';
    $display->content['new-7f4b7eb1-f562-448a-a3a1-83d48d2d83c2'] = $pane;
    $display->panels['bottom'][0] = 'new-7f4b7eb1-f562-448a-a3a1-83d48d2d83c2';
    $pane = new stdClass();
    $pane->pid = 'new-7175a195-4271-47e4-890d-b5780a681f00';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'superfish-3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7175a195-4271-47e4-890d-b5780a681f00';
    $display->content['new-7175a195-4271-47e4-890d-b5780a681f00'] = $pane;
    $display->panels['left'][0] = 'new-7175a195-4271-47e4-890d-b5780a681f00';
    $pane = new stdClass();
    $pane->pid = 'new-7ce40d72-da02-4d9c-89b7-9abd049c91fc';
    $pane->panel = 'right';
    $pane->type = 'coral_ask_question';
    $pane->subtype = 'coral_ask_question';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7ce40d72-da02-4d9c-89b7-9abd049c91fc';
    $display->content['new-7ce40d72-da02-4d9c-89b7-9abd049c91fc'] = $pane;
    $display->panels['right'][0] = 'new-7ce40d72-da02-4d9c-89b7-9abd049c91fc';
    $pane = new stdClass();
    $pane->pid = 'new-87bd5a2e-d5a9-4b20-935c-c6040f692bf6';
    $pane->panel = 'right';
    $pane->type = 'coral_contact_us';
    $pane->subtype = 'coral_contact_us';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'hide',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '87bd5a2e-d5a9-4b20-935c-c6040f692bf6';
    $display->content['new-87bd5a2e-d5a9-4b20-935c-c6040f692bf6'] = $pane;
    $display->panels['right'][1] = 'new-87bd5a2e-d5a9-4b20-935c-c6040f692bf6';
    $pane = new stdClass();
    $pane->pid = 'new-03369ad3-e02b-4ef4-8981-7db36d6f1eae';
    $pane->panel = 'top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Help title',
      'title' => '',
      'body' => '<h2 class=\'grid-6\'>Have questions?</h2><div class=\'title-msg grid-18-last\'>From this screen you can ask the community questions, find helpful links and related documentation, or contact us directly.</div>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'help-header clearfix',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '03369ad3-e02b-4ef4-8981-7db36d6f1eae';
    $display->content['new-03369ad3-e02b-4ef4-8981-7db36d6f1eae'] = $pane;
    $display->panels['top'][0] = 'new-03369ad3-e02b-4ef4-8981-7db36d6f1eae';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-7175a195-4271-47e4-890d-b5780a681f00';
  $mini->display = $display;
  $export['getting_help'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'header';
  $mini->category = 'Coral';
  $mini->admin_title = 'Header';
  $mini->admin_description = 'Coral Nexus header mini-panel';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '66448742-1234-4bff-8ebb-0f6e58473a77';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-53ec0a82-91c9-4a85-bbb6-b8823b5d8d62';
    $pane->panel = 'bottom';
    $pane->type = 'block';
    $pane->subtype = 'hybridauth-hybridauth';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'right',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '53ec0a82-91c9-4a85-bbb6-b8823b5d8d62';
    $display->content['new-53ec0a82-91c9-4a85-bbb6-b8823b5d8d62'] = $pane;
    $display->panels['bottom'][0] = 'new-53ec0a82-91c9-4a85-bbb6-b8823b5d8d62';
    $pane = new stdClass();
    $pane->pid = 'new-1eeaa396-0d69-48de-a58e-d501b979d85e';
    $pane->panel = 'bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Coral cloud icon',
      'title' => '',
      'body' => '<div class="coral-cloud"><span class="icon"></span></div>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1eeaa396-0d69-48de-a58e-d501b979d85e';
    $display->content['new-1eeaa396-0d69-48de-a58e-d501b979d85e'] = $pane;
    $display->panels['bottom'][1] = 'new-1eeaa396-0d69-48de-a58e-d501b979d85e';
    $pane = new stdClass();
    $pane->pid = 'new-efc35b19-f2fd-4089-83d7-6c985a9d4ff1';
    $pane->panel = 'left';
    $pane->type = 'coral_logo';
    $pane->subtype = 'coral_logo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'left',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'efc35b19-f2fd-4089-83d7-6c985a9d4ff1';
    $display->content['new-efc35b19-f2fd-4089-83d7-6c985a9d4ff1'] = $pane;
    $display->panels['left'][0] = 'new-efc35b19-f2fd-4089-83d7-6c985a9d4ff1';
    $pane = new stdClass();
    $pane->pid = 'new-9c2a68f2-f314-409f-85e1-613742447aa3';
    $pane->panel = 'left';
    $pane->type = 'page_logo';
    $pane->subtype = 'page_logo';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'left',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '9c2a68f2-f314-409f-85e1-613742447aa3';
    $display->content['new-9c2a68f2-f314-409f-85e1-613742447aa3'] = $pane;
    $display->panels['left'][1] = 'new-9c2a68f2-f314-409f-85e1-613742447aa3';
    $pane = new stdClass();
    $pane->pid = 'new-f2fedd89-c457-4ad6-b7c1-413bc67ebcc9';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'search-form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'left',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'f2fedd89-c457-4ad6-b7c1-413bc67ebcc9';
    $display->content['new-f2fedd89-c457-4ad6-b7c1-413bc67ebcc9'] = $pane;
    $display->panels['left'][2] = 'new-f2fedd89-c457-4ad6-b7c1-413bc67ebcc9';
    $pane = new stdClass();
    $pane->pid = 'new-e566893d-af0a-4363-96dc-a2c156036ee3';
    $pane->panel = 'left';
    $pane->type = 'page_site_name';
    $pane->subtype = 'page_site_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'left hide',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'e566893d-af0a-4363-96dc-a2c156036ee3';
    $display->content['new-e566893d-af0a-4363-96dc-a2c156036ee3'] = $pane;
    $display->panels['left'][3] = 'new-e566893d-af0a-4363-96dc-a2c156036ee3';
    $pane = new stdClass();
    $pane->pid = 'new-f832146e-74c4-4e94-907d-5da04067fef5';
    $pane->panel = 'left';
    $pane->type = 'page_slogan';
    $pane->subtype = 'page_slogan';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'left hide',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'f832146e-74c4-4e94-907d-5da04067fef5';
    $display->content['new-f832146e-74c4-4e94-907d-5da04067fef5'] = $pane;
    $display->panels['left'][4] = 'new-f832146e-74c4-4e94-907d-5da04067fef5';
    $pane = new stdClass();
    $pane->pid = 'new-fd016236-a292-4960-84f3-4318d4508809';
    $pane->panel = 'right';
    $pane->type = 'coral_user';
    $pane->subtype = 'coral_user';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'welcome_text' => 'Welcome back ',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fd016236-a292-4960-84f3-4318d4508809';
    $display->content['new-fd016236-a292-4960-84f3-4318d4508809'] = $pane;
    $display->panels['right'][0] = 'new-fd016236-a292-4960-84f3-4318d4508809';
    $pane = new stdClass();
    $pane->pid = 'new-bf890e76-ecf4-4457-824f-16e2276e576a';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'menu-support';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'bf890e76-ecf4-4457-824f-16e2276e576a';
    $display->content['new-bf890e76-ecf4-4457-824f-16e2276e576a'] = $pane;
    $display->panels['top'][0] = 'new-bf890e76-ecf4-4457-824f-16e2276e576a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9c2a68f2-f314-409f-85e1-613742447aa3';
  $mini->display = $display;
  $export['header'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'top_menus';
  $mini->category = 'Coral';
  $mini->admin_title = 'Top menus';
  $mini->admin_description = 'Primary and service menus.';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '581c71a0-a115-48de-8050-def3816d8909';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0a992731-3566-48a7-8a3c-bc93b6dfa033';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'superfish-1';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'left',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0a992731-3566-48a7-8a3c-bc93b6dfa033';
    $display->content['new-0a992731-3566-48a7-8a3c-bc93b6dfa033'] = $pane;
    $display->panels['left'][0] = 'new-0a992731-3566-48a7-8a3c-bc93b6dfa033';
    $pane = new stdClass();
    $pane->pid = 'new-63c552c0-337d-4016-9050-33d90d43244f';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'menu-main';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '63c552c0-337d-4016-9050-33d90d43244f';
    $display->content['new-63c552c0-337d-4016-9050-33d90d43244f'] = $pane;
    $display->panels['left'][1] = 'new-63c552c0-337d-4016-9050-33d90d43244f';
    $pane = new stdClass();
    $pane->pid = 'new-0823eb88-f545-4a64-8775-11ef25c05cf3';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'superfish-2';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'right',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0823eb88-f545-4a64-8775-11ef25c05cf3';
    $display->content['new-0823eb88-f545-4a64-8775-11ef25c05cf3'] = $pane;
    $display->panels['right'][0] = 'new-0823eb88-f545-4a64-8775-11ef25c05cf3';
    $pane = new stdClass();
    $pane->pid = 'new-17e884d5-697a-454f-963c-f96d748ad44c';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'menu-service';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '17e884d5-697a-454f-963c-f96d748ad44c';
    $display->content['new-17e884d5-697a-454f-963c-f96d748ad44c'] = $pane;
    $display->panels['right'][1] = 'new-17e884d5-697a-454f-963c-f96d748ad44c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['top_menus'] = $mini;

  return $export;
}
