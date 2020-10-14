<?php

class schema__license_formatter extends ChadoFieldFormatter {

  // The default label for this field.
  public static $default_label = 'License';

  // The list of field types for which this formatter is appropriate.
  public static $field_types = ['schema__license'];


  /**
   *
   * @see TripalFieldFormatter::settingsForm()
   */
  public function settingsForm($view_mode, $form, &$form_state) {

  }

  /**
   *
   * @see TripalFieldFormatter::view()
   */
  public function view(&$element, $entity_type, $entity, $langcode, $items, $display) {

    $name_term = chado_get_semweb_term('license', 'name');
    $summary_term = chado_get_semweb_term('license', 'summary');
    $uri_term = chado_get_semweb_term('license', 'uri');

    $element[] = [
      [
        '#type' => 'item',
        '#title' => 'License Name',
        '#markup' => $items[0]['value'][$name_term],
      ],
      [
        '#type' => 'item',
        '#title' => 'Summary',
        '#markup' => $items[0]['value'][$summary_term],
      ],
      [
        '#type' => 'item',
        '#title' => 'Full Details',
        '#markup' => $items[0]['value'][$uri_term],
      ],
    ];
  }
}