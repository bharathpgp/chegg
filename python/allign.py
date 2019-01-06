def main():
    file = open("bad_receipt.txt", "r")
    lines = file.readlines()
    file.close()

    itemLine = False
    modified_lines = []
    for line in lines:
        modified_line = line.strip()
        if 'Store' in modified_line:
            modified_lines.extend([x.upper()
                                   for x in modified_line.split(' ')])
        if 'Clerk' in modified_line or 'SUBTOTAL' in modified_line or 'TAX' in modified_line or 'TOTAL' in modified_line:
            if itemLine:
                itemLine = False
                modified_lines.append('-'*80)
            temp = modified_line.split(':')
            modified_lines.append(temp[0].upper())
            if temp[0] == 'Clerk':
                modified_lines.append(
                    ', '.join(temp[1].strip().split(' ')[::-1]))
            else:
                if 'SUBTOTAL' in modified_line or 'TOTAL' in modified_line:
                    modified_lines.append(
                        "(-0.01) " + temp[1].strip().replace(',', ''))
                else:
                    modified_lines.append(temp[1].strip())
        if 'MEMBER' in modified_line:
            temp = modified_line.split('#')
            modified_lines.append(temp[0].strip() + '#')
            modified_lines.append(temp[1].strip())
        if 'E' in modified_line and '$' in modified_line:
            if not itemLine:
                itemLine = True
                modified_lines.append('-'*80)

            temp = modified_line.split(' ', 2)
            str = temp[2].rsplit(' ', 1)[0] + ' #' + temp[1] + '\n'
            str += temp[2].rsplit(' ', 1)[1]
            modified_lines.append('ITEM: ' + str)
    for line in modified_lines:
        print(line)


main()
