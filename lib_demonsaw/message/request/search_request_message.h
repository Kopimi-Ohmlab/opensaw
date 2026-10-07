// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef _EJA_SEARCH_REQUEST_MESSAGE_
#define _EJA_SEARCH_REQUEST_MESSAGE_

#include <memory>

#include "json/json.h"
#include "json/json_message.h"
#include "json/json_value.h"

namespace eja
{
	class search_request_message final : public json_message
	{
	public:
		using ptr = std::shared_ptr<search_request_message>;

	private:
		search_request_message() : json_message(json_type::search, json_action::request) { }
		search_request_message(const json_message::ptr& message) : json_message(message, json_type::search, json_action::request) { }
		search_request_message(const json_value::ptr& value) : json_message(value, json_type::search, json_action::request) { }

	public:      
		virtual ~search_request_message() override { }

		// Static
		static ptr create() { return ptr(new search_request_message()); }
		static ptr create(const json_message::ptr& message) { return ptr(new search_request_message(message)); }
		static ptr create(const json_value::ptr& value) { return ptr(new search_request_message(value)); }
	};
}

#endif
