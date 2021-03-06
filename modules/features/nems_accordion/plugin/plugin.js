/**
 * @file
 * Ckeditor plugin file.
 */

(function ($) {
  CKEDITOR.plugins.add('nems_accordion_plugin', {
    init: function (editor) {
      editor.addCommand('add_accordion', {
        exec : function (editor) {
          // Create the wrapper div.
          var accr = editor.document.createElement('div');
          accr.setAttribute('class', 'accordion');

          // Create an h3 element to the title.
          var accr_title = editor.document.createElement('h3');
          accr_title.setText('Accordion Title');

          // Append the title into wrapper div.
          accr.append(accr_title);

          // Create a div element for the content of accordion.
          var accr_content = editor.document.createElement('div');
          accr_content.setAttribute('class', 'accordion-content');

          // Create the first paragraph.
          var accr_content_p1 = editor.document.createElement('p');
          accr_content_p1.setText('Donec ullamcorper nulla non metus auctor fringilla. Vestibulum id ligula porta felis euismod semper. Donec ullamcorper nulla non metus auctor fringilla. Duis mollis, est non commodo luctus, nisi erat porttitor ligula, eget lacinia odio sem nec elit. Donec sed odio dui. Morbi leo risus, porta ac consectetur ac, vestibulum at eros.');

          // Create the second paragraph.
          var accr_content_p2 = editor.document.createElement('p');
          accr_content_p2.setText('Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Maecenas sed diam eget risus varius blandit sit amet non magna. Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Donec id elit non mi porta gravida at eget metus. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Nulla vitae elit libero, a pharetra augue. Nullam quis risus eget urna mollis ornare vel eu leo.');

          // Append the paragraphs into the content div.
          accr_content.append(accr_content_p1);
          accr_content.append(accr_content_p2);

          // Append the content div into accordion wrapper.
          accr.append(accr_content);

          // Create a hidden paragraph.
          var accr_content_phidden = editor.document.createElement('p');
          accr_content_phidden.setAttribute('class', 'hidden');

          // Append the hidden paragraph into accordion wrapper.
          accr.append(accr_content_phidden);

          // Validate accordion.
          var parents = editor.getSelection().getStartElement().getParents();
          var parentIndex;
          var isAccordion;

          for (parentIndex = 0; parentIndex < parents.length; ++parentIndex) {
            if (parents[parentIndex].hasClass('accordion')) {
              parents[parentIndex].append(accr_title);
              parents[parentIndex].append(accr_content);
              isAccordion = true;
            }
          }

          // Insert the accordion HTML to the editor if it's not an existing accordion.
          if (isAccordion != true) {
            editor.insertElement(accr);
          }

        }
      });
      editor.ui.addButton('nems_accordion_plugin_button', {
        label: 'Insert an Accordion',
        command: 'add_accordion',
        icon: this.path + 'images/button.png'
      });
    }
  });
})(jQuery);
