<?php
/**
 * @file
 * text_formats_feature.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function text_formats_feature_filter_default_formats() {
  $formats = array();

  // Exported format: Filtered HTML.
  $formats['filtered_html'] = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'filter_html' => array(
        'weight' => -50,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <pre> <ul> <ol> <li> <dl> <dt> <dd> <h2> <h3> <h4> <span> <p> <box> <br> <sub> <sup> <hlite> <img> <clear> <small>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'freelinking' => array(
        'weight' => -49,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_markdown' => array(
        'weight' => -48,
        'status' => 1,
        'settings' => array(),
      ),
      'Mediawiki Format' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(),
      ),
      'typogrify' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(
          'smartypants_enabled' => 0,
          'smartypants_hyphens' => 2,
          'wrap_ampersand' => 0,
          'widont_enabled' => 0,
          'hyphenate_shy' => 0,
          'wrap_abbr' => 0,
          'wrap_caps' => 0,
          'wrap_initial_quotes' => 0,
          'wrap_numbers' => 0,
          'ligatures' => array(
            'ffi' => 0,
            'ffl' => 0,
            'ff' => 0,
            'fi' => 0,
            'fl' => 0,
            'ij' => 0,
            'IJ' => 0,
            'st' => 0,
            'ss' => 0,
          ),
          'arrows' => array(
            '-&gt;&gt;' => 0,
            '&lt;&lt;-' => 0,
            '-&gt;|' => 0,
            '|&lt;-' => 0,
            '&lt;-&gt;' => 0,
            '-&gt;' => 0,
            '&lt;-' => 0,
            '&lt;=&gt;' => 0,
            '=&gt;' => 0,
            '&lt;=' => 0,
          ),
          'fractions' => array(
            '1/4' => 0,
            '1/2' => 0,
            '3/4' => 0,
            '1/3' => 0,
            '2/3' => 0,
            '1/5' => 0,
            '2/5' => 0,
            '3/5' => 0,
            '4/5' => 0,
            '1/6' => 0,
            '5/6' => 0,
            '1/8' => 0,
            '3/8' => 0,
            '5/8' => 0,
            '7/8' => 0,
          ),
          'quotes' => array(
            ',,' => 0,
            '\'\'' => 0,
            '&lt;&lt;' => 0,
            '&gt;&gt;' => 0,
          ),
          'space_to_nbsp' => 0,
        ),
      ),
      'filter_autop' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -9,
    'filters' => array(
      'freelinking' => array(
        'weight' => -50,
        'status' => 1,
        'settings' => array(),
      ),
      'Mediawiki Format' => array(
        'weight' => -49,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_markdown' => array(
        'weight' => -48,
        'status' => 1,
        'settings' => array(),
      ),
      'typogrify' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(
          'smartypants_enabled' => 1,
          'smartypants_hyphens' => 2,
          'wrap_ampersand' => 1,
          'widont_enabled' => 1,
          'hyphenate_shy' => 0,
          'wrap_abbr' => 0,
          'wrap_caps' => 1,
          'wrap_initial_quotes' => 1,
          'wrap_numbers' => 0,
          'ligatures' => array(
            'ffi' => 0,
            'ffl' => 0,
            'ff' => 0,
            'fi' => 0,
            'fl' => 0,
            'ij' => 0,
            'IJ' => 0,
            'st' => 0,
            'ss' => 0,
          ),
          'arrows' => array(
            '-&gt;&gt;' => 0,
            '&lt;&lt;-' => 0,
            '-&gt;|' => 0,
            '|&lt;-' => 0,
            '&lt;-&gt;' => 0,
            '-&gt;' => 0,
            '&lt;-' => 0,
            '&lt;=&gt;' => 0,
            '=&gt;' => 0,
            '&lt;=' => 0,
          ),
          'fractions' => array(
            '1/4' => 0,
            '1/2' => 0,
            '3/4' => 0,
            '1/3' => 0,
            '2/3' => 0,
            '1/5' => 0,
            '2/5' => 0,
            '3/5' => 0,
            '4/5' => 0,
            '1/6' => 0,
            '5/6' => 0,
            '1/8' => 0,
            '3/8' => 0,
            '5/8' => 0,
            '7/8' => 0,
          ),
          'quotes' => array(
            ',,' => ',,',
            '\'\'' => '\'\'',
            '&lt;&lt;' => '&lt;&lt;',
            '&gt;&gt;' => '&gt;&gt;',
          ),
          'space_to_nbsp' => 1,
        ),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => 1,
    'status' => 1,
    'weight' => -8,
    'filters' => array(
      'filter_html_escape' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
